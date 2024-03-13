/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:24:18 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 10:22:30 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/map.h"
#include <stdbool.h>

static void	check_map_validity(t_data *d, t_map *map);
static bool	is_surrounded_by_wall(t_map *map);

void	init_map(t_data *data, char *map_path)
{
	data->map = malloc(sizeof(t_map));
	track_allocation(data, data->map);
	data->map->grid = NULL;
	data->map->width = 0;
	data->map->height = 0;
	import_map(data, map_path);
	check_map_validity(data, data->map);
}

static void	check_map_validity(t_data *d, t_map *map)
{
	if (count_block(map, NULL_BLOCK) > 0)
		put_error(d, "Invalid character in map");
	if (count_block(map, PLAYER) != 1)
		put_error(d, "Map should have exactly one starting point");
	if (count_block(map, EXIT) != 1)
		put_error(d, "Map should have exactly one exit");
	if (count_block(map, COLLECTIBLE) < 1)
		put_error(d, "Map should have at least one collectible");
	if (!is_surrounded_by_wall(map))
		put_error(d, "Map should be surrounded by walls");
	check_valid_path(d, map);
}

static bool	is_surrounded_by_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != WALL || map->grid[map->height - 1][i] != WALL)
			return (false);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != WALL || map->grid[i][map->width - 1] != WALL)
			return (false);
		i++;
	}
	return (true);
}
