/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:46:37 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/02 23:46:47 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

ssize_t	ft_write_fd(const char *s, int fd)
{
	if (!s)
		return (-1);
	return (write(fd, s, ft_strlen(s)));
}
