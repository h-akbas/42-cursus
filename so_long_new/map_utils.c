/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:09:20 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 18:36:13 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_block(t_map *map, t_block block_type)
{
	int		count;
	t_pos	pos;

	count = 0;
	pos.y = -1;
	while (++pos.y < map->y)
	{
		pos.x = -1;
		while (++pos.x < map->x)
			if (map->grid[pos.y][pos.x] == block_type)
				count++;
	}
	return (count);
}

t_pos	get_position(t_map *map, t_block block_type)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < map->y)
	{
		pos.x = 0;
		while (pos.x < map->x)
		{
			if (map->grid[pos.y][pos.x] == block_type)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	return (pos);
}