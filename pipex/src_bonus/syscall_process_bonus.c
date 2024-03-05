/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:56:53 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 21:05:26 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int	safe_execve(const char *pathname, char *const argv[], char *const envp[],
		t_data *data)
{
	int	ret;

	ret = execve(pathname, argv, envp);
	if (ret == -1)
		put_sys_error("execve", errno, data);
	return (ret);
}

pid_t	safe_fork(t_data *data)
{
	pid_t	ret;

	ret = fork();
	if (ret == -1)
		put_sys_error("fork", errno, data);
	return (ret);
}

int	safe_pipe(int pipefd[2], t_data *data)
{
	int	ret;

	ret = pipe(pipefd);
	if (ret == -1)
		put_sys_error("pipe", errno, data);
	return (ret);
}

pid_t	safe_wait(int *wstatus, t_data *data)
{
	pid_t	ret;

	ret = wait(wstatus);
	if (ret == -1)
		put_sys_error("wait", errno, data);
	return (ret);
}
