/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:56:53 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:42:10 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <sys/wait.h>
#include <unistd.h>

int	safe_execve(const char *pathname, char *const argv[], char *const envp[],
		t_data *d)
{
	int	ret;

	ret = execve(pathname, argv, envp);
	if (ret == -1)
		put_sys_error("execve", errno, d);
	return (ret);
}

pid_t	safe_fork(t_data *d)
{
	pid_t	ret;

	ret = fork();
	if (ret == -1)
		put_sys_error("fork", errno, d);
	return (ret);
}

int	safe_pipe(int pipefd[2], t_data *d)
{
	int	ret;

	ret = pipe(pipefd);
	if (ret == -1)
		put_sys_error("pipe", errno, d);
	return (ret);
}

pid_t	safe_wait(int *wstatus, t_data *d)
{
	pid_t	ret;

	ret = wait(wstatus);
	if (ret == -1)
		put_sys_error("wait", errno, d);
	return (ret);
}
