/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:35:51 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 20:42:09 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "../include/pipex.h"

void	*safe_alloc(void *pointer, t_alloc mode, t_data *data)
{
	if (!pointer)
		put_error("Memory allocation", strerror(errno), EXIT_FAILURE, data);
	if (mode == TRACK)
	{
		if (!track_alloc(data, pointer))
			pointer = NULL;
	}
	return (pointer);
}

int	track_alloc(t_data *data, void *pointer)
{
	t_list	*new_node;

	new_node = ft_lstnew(pointer);
	if (!new_node)
	{
		free(pointer);
		put_error("Memory allocation", strerror(errno), EXIT_FAILURE, data);
		return (0);
	}
	ft_lstadd_front(&data->allocated_pointers, new_node);
	return (1);
}
