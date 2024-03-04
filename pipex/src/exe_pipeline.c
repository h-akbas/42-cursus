/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:51:48 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:45:43 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>
#include <unistd.h>

static pid_t	execute_command(t_data *d, int prev_read_end, int p[2],
					int i_cmd);
static void		setup_for_next_command(int *prev_read_end, int p[2],
					t_data *d);
static void		wait_for_children(t_data *d, pid_t last_pid);

void	execute_pipeline(t_data *d)
{
	int		p[2];
	int		prev_read_end;
	pid_t	last_pid;
	int		i;

	prev_read_end = -1;
	setup_input(d->input_file, d->limiter, d);
	setup_output(d->output_file, d);
	i = 0;
	while (i < d->n_cmd)
	{
		safe_pipe(p, d);
		last_pid = execute_command(d, prev_read_end, p, i);
		setup_for_next_command(&prev_read_end, p, d);
		i++;
	}
	wait_for_children(d, last_pid);
}

static pid_t	execute_command(t_data *d, int prev_read_end, int p[2],
					int i_cmd)
{
	pid_t	pid;
	char	**cmd_exe;

	pid = safe_fork(d);
	if (pid != 0)
		return (pid);
	if (prev_read_end != -1)
	{
		safe_dup2(prev_read_end, STDIN_FILENO, d);
		safe_close(prev_read_end, d);
	}
	if (i_cmd < d->n_cmd - 1)
		safe_dup2(p[WRITE_END], STDOUT_FILENO, d);
	safe_close(p[READ_END], d);
	safe_close(p[WRITE_END], d);
	cmd_exe = d->commands[i_cmd];
	safe_execve(get_bin_path(cmd_exe[0], d->env_paths, d), cmd_exe, d->env, d);
	return (pid);
}

static void	setup_for_next_command(int *prev_read_end, int p[2], t_data *d)
{
	if (*prev_read_end != -1)
		safe_close(*prev_read_end, d);
	safe_close(p[WRITE_END], d);
	*prev_read_end = p[READ_END];
}

static void	wait_for_children(t_data *d, pid_t last_pid)
{
	int		i;
	pid_t	child_pid;
	int		status;

	i = 0;
	while (i < d->n_cmd)
	{
		child_pid = safe_wait(&status, d);
		if (child_pid == last_pid && WIFEXITED(status))
			d->last_cmd_exit_status = WEXITSTATUS(status);
		i++;
	}
}
