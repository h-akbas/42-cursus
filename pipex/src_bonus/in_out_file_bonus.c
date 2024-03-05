/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_out_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:52:22 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 21:22:06 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include "../lib/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void	report_errno(char *context, t_data *data);
static int	heredoc_handler(char *limiter, t_data *data);
static int	read_heredoc_lines(int tmp_fd, char *limiter, t_data *data);

void	set_infile(char *filename, char *limiter, t_data *data)
{
	int	input_fd;

	if (limiter != NULL)
		input_fd = heredoc_handler(limiter, data);
	else
	{
		input_fd = open(filename, O_RDONLY);
		if (input_fd == -1)
		{
			report_errno(filename, data);
			input_fd = safe_open("/dev/null", O_RDONLY, 0, data);
		}
	}
	safe_dup2(input_fd, STDIN_FILENO, data);
	safe_close(input_fd, data);
}

void	set_outfile(char *filename, t_data *data)
{
	int	output_fd;

	output_fd = safe_open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0644, data);
	safe_dup2(output_fd, STDOUT_FILENO, data);
	safe_close(output_fd, data);
}

static void	report_errno(char *context, t_data *data)
{
	safe_write_fd("pipex: ", 2, data);
	perror(context);
}

static int	read_heredoc_lines(int tmp_fd, char *limiter, t_data *data)
{
	char	*line;
	int		gnl_status;

	gnl_status = EXIT_SUCCESS;
	while (gnl_status == EXIT_SUCCESS)
	{
		gnl_status = get_next_line(0, &line);
		if (gnl_status == EXIT_FAILURE)
			put_error("get_next_line", "fail to read heredoc",
				EXIT_FAILURE, data);
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		safe_write_fd(line, tmp_fd, data);
		free(line);
	}
	return (gnl_status);
}

static int	heredoc_handler(char *limiter, t_data *data)
{
	int		tmp_fd;
	int		gnl_status;

	tmp_fd = safe_open("/tmp/.pp_heredoc", O_WRONLY | O_CREAT | O_TRUNC,
			0600, data);
	gnl_status = read_heredoc_lines(tmp_fd, limiter, data);
	if (gnl_status == EXIT_FAILURE)
	{
		safe_close(tmp_fd, data);
		return (EXIT_FAILURE);
	}
	safe_close(tmp_fd, data);
	tmp_fd = safe_open("/tmp/.pp_heredoc", O_RDONLY, 0600, data);
	safe_unlink("/tmp/.pp_heredoc", data);
	return (tmp_fd);
}
