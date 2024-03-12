/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:20:43 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:43:57 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"
#include "../inc/so_long.h"

void	init_data(t_data *data, char *map_path)
{
	data->allocated_pointers = NULL;
	data->state = PLAYING;
	data->mlx = NULL;
	init_map(data, map_path);
	data->player = get_position(data->map, PLAYER);
	data->player_orientation = UP;
	data->exit = get_position(data->map, EXIT);
	data->exit_status = CLOSED;
	data->collectible_count = count_block(data->map, COLLECTIBLE);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	ft_lstclear(&data->allocated_pointers, &free);
	if (data->mlx)
		free(data->mlx);
}

void	track_allocation(t_data *data, void *pointer)
{
	t_list	*new_node;

	(void)data;
	if (!pointer)
		put_error(data, "A memory allocation failed");
	new_node = ft_lstnew(pointer);
	if (!new_node)
		put_error(data, "A memory allocation failed");
	ft_lstadd_front(&data->allocated_pointers, new_node);
}
