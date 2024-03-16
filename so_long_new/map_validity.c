/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:03:02 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 19:07:03 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	surrounded_by_wall(t_map *map);

void	check_map_validity(t_data *d, t_map *map)
{
    ft_assert(count_block(map, NULL_BLOCK) < 1, "Invalid character in map", d);
    ft_assert(count_block(map, PLAYER) == 1, "Only one player!", d);
    ft_assert(count_block(map, EXIT) == 1, "Only one exit", d);
    ft_assert(count_block(map, COLLECTIBLE) > 0, "At least one collectible", d);
    ft_assert(surrounded_by_wall(map), "Invalid wall", d);
	check_valid_path(d, map);
}

static bool	surrounded_by_wall(t_map *map)
{
	size_t  i;

	i = 0;
	while (i < map->x)
	{
		if (map->grid[0][i] != WALL || map->grid[map->y - 1][i] != WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->y)
	{
		if (map->grid[i][0] != WALL || map->grid[i][map->x - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}