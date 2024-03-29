/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall_file_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:55:48 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 21:05:06 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int	safe_open(const char *pathname, int flags, mode_t mode, t_data *data)
{
	int	ret;

	ret = open(pathname, flags, mode);
	if (ret == -1)
		put_sys_error(pathname, errno, data);
	return (ret);
}

int	safe_close(int fd, t_data *data)
{
	int	ret;

	ret = close(fd);
	if (ret == -1)
		put_sys_error("close", errno, data);
	return (ret);
}

int	safe_dup2(int oldfd, int newfd, t_data *data)
{
	int	ret;

	ret = dup2(oldfd, newfd);
	if (ret == -1)
		put_sys_error("dup2", errno, data);
	return (ret);
}

int	safe_unlink(const char *pathname, t_data *data)
{
	int	ret;

	ret = unlink(pathname);
	if (ret == -1)
		put_sys_error("unlink", errno, data);
	return (ret);
}
