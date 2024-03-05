/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:51:48 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 21:17:53 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>
#include <unistd.h>

static pid_t	execute_command(t_data *data, int prev_read_end, int p[2],
					int i_cmd);
static void		setup_for_next_command(int *prev_read_end, int p[2],
					t_data *data);
static void		wait_for_children(t_data *data, pid_t last_pid);

void	execute_pipeline(t_data *data)
{
	int		p[2];
	int		prev_read_end;
	pid_t	last_pid;
	int		i;

	prev_read_end = -1;
	last_pid = 0;
	set_infile(data->input_file, data->limiter, data);
	set_outfile(data->output_file, data);
	i = 0;
	while (i < data->n_cmd)
	{
		safe_pipe(p, data);
		last_pid = execute_command(data, prev_read_end, p, i);
		setup_for_next_command(&prev_read_end, p, data);
		i++;
	}
	wait_for_children(data, last_pid);
}

static pid_t	execute_command(t_data *data, int prev_read_end, int p[2],
					int i_cmd)
{
	pid_t	pid;
	char	**cmd_exe;

	pid = safe_fork(data);
	if (pid != 0)
		return (pid);
	if (prev_read_end != -1)
	{
		safe_dup2(prev_read_end, STDIN_FILENO, data);
		safe_close(prev_read_end, data);
	}
	if (i_cmd < data->n_cmd - 1)
		safe_dup2(p[WRITE_END], STDOUT_FILENO, data);
	safe_close(p[READ_END], data);
	safe_close(p[WRITE_END], data);
	cmd_exe = data->commands[i_cmd];
	safe_execve(get_bin_path(cmd_exe[0], data->env_paths, data),
		cmd_exe, data->env, data);
	return (pid);
}

static void	setup_for_next_command(int *prev_read_end, int p[2], t_data *data)
{
	if (*prev_read_end != -1)
		safe_close(*prev_read_end, data);
	safe_close(p[WRITE_END], data);
	*prev_read_end = p[READ_END];
}

static void	wait_for_children(t_data *data, pid_t last_pid)
{
	int		i;
	pid_t	child_pid;
	int		status;

	i = 0;
	while (i < data->n_cmd)
	{
		child_pid = safe_wait(&status, data);
		if (child_pid == last_pid && WIFEXITED(status))
			data->last_cmd_exit_status = WEXITSTATUS(status);
		i++;
	}
}
