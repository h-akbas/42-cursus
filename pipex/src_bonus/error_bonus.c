/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:44:42 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:55:37 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void	put_error(const char *context, char *description, int exit_status,
		t_data *d)
{
	ft_write_fd("pipex: ", 2);
	ft_write_fd(description, 2);
	ft_write_fd(": ", 2);
	ft_write_fd(context, 2);
	ft_write_fd("\n", 2);
	if (d)
		ft_lstclear(&d->allocated_pointers, free);
	exit(exit_status);
}

void	put_sys_error(const char *context, int errnum, t_data *d)
{
	put_error(context, strerror(errnum), EXIT_FAILURE, d);
}

ssize_t	safe_write_fd(const void *buf, int fd, t_data *d)
{
	ssize_t	ret;

	ret = ft_write_fd(buf, fd);
	if (ret == -1)
		put_sys_error("ft_write_fd", errno, d);
	return (ret);
}
