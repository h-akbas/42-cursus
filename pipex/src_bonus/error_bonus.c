/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:44:42 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 20:51:33 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>

void	put_error(const char *context, char *description, int exit_status,
		t_data *data)
{
	ft_write_fd("pipex: ", 2);
	ft_write_fd(description, 2);
	ft_write_fd(": ", 2);
	ft_write_fd(context, 2);
	ft_write_fd("\n", 2);
	if (data)
		ft_lstclear(&data->allocated_pointers, free);
	exit(exit_status);
}

void	put_sys_error(const char *context, int errnum, t_data *data)
{
	put_error(context, strerror(errnum), EXIT_FAILURE, data);
}

ssize_t	safe_write_fd(const void *buf, int fd, t_data *data)
{
	ssize_t	ret;

	ret = ft_write_fd(buf, fd);
	if (ret == -1)
		put_sys_error("ft_write_fd", errno, data);
	return (ret);
}
