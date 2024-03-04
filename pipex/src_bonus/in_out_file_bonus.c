/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:52:22 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:59:59 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void	report_errno(char *context, t_data *d);
static int	heredoc_listener(char *limiter, t_data *d);

void	setup_input(char *filename, char *limiter, t_data *d)
{
	int	input_fd;

	if (limiter != NULL)
		input_fd = heredoc_listener(limiter, d);
	else
	{
		input_fd = open(filename, O_RDONLY);
		if (input_fd == -1)
		{
			report_errno(filename, d);
			input_fd = safe_open("/dev/null", O_RDONLY, 0, d);
		}
	}
	safe_dup2(input_fd, STDIN_FILENO, d);
	safe_close(input_fd, d);
}

void	setup_output(char *filename, t_data *d)
{
	int	output_fd;

	output_fd = safe_open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644, d);
	safe_dup2(output_fd, STDOUT_FILENO, d);
	safe_close(output_fd, d);
}

static void	report_errno(char *context, t_data *d)
{
	safe_write_fd("pipex: ", 2, d);
	perror(context);
}

static int	heredoc_listener(char *limiter, t_data *d)
{
	int		tmp_fd;
	char	*line;
	int		gnl_status;

	tmp_fd = safe_open("/tmp/.pp_heredoc", O_WRONLY | O_CREAT
			| O_TRUNC, 0600, d);
	gnl_status = EXIT_SUCCESS;
	while (gnl_status == EXIT_SUCCESS)
	{
		gnl_status = get_next_line(0, &line);
		if (gnl_status == EXIT_FAILURE)
			put_error("get_next_line", "fail to read heredoc", EXIT_FAILURE, d);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		safe_write_fd(line, tmp_fd, d);
		free(line);
	}
	safe_close(tmp_fd, d);
	tmp_fd = safe_open("/tmp/.pp_heredoc", O_RDONLY, 0600, d);
	safe_unlink("/tmp/.pp_heredoc", d);
	return (tmp_fd);
}
