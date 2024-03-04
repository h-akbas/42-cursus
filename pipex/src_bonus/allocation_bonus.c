/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:35:51 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:42:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "../include/pipex.h"

void	*s_alloc(void *pointer, t_alloc mode, t_data *d)
{
	if (!pointer)
		put_error("Memory allocation", strerror(errno), EXIT_FAILURE, d);
	if (mode == TRACK)
		track_alloc(d, pointer);
	return (pointer);
}

void	track_alloc(t_data *d, void *pointer)
{
	t_list	*new_node;

	new_node = ft_lstnew(pointer);
	if (!new_node)
	{
		free(pointer);
		put_error("Memory allocation", strerror(errno), EXIT_FAILURE, d);
	}
	ft_lstadd_front(&d->allocated_pointers, new_node);
}
