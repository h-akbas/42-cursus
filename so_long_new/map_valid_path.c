/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:14:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 19:08:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

static void	depth_first_search(t_map *map, t_pos *pos, bool **visited,
		int reachable[2]);
static bool	**init_visited(t_data *d, t_map *map);

void	check_valid_path(t_data *d, t_map *map)
{
	int		reachable[BLOCK_NUMBER];
	t_pos	pos;

	reachable[COLLECTIBLE] = 0;
	reachable[EXIT] = 0;
	pos = get_position(d->map, PLAYER);
	depth_first_search(map, &pos, init_visited(d, map), reachable);
	ft_assert(reachable[COLLECTIBLE] == count_block(map, COLLECTIBLE),
        "Map should have a valid path to all collectibles", d);
	ft_assert(reachable[EXIT] == 1, "Map should have a valid path to the exit", d);
}

void	depth_first_search(t_map *map, t_pos *pos, bool **visited,
		int reachable[2])
{
	t_pos	new_pos;
	t_block	current;

	current = map->grid[pos->y][pos->x];
	if (current == EXIT)
		reachable[EXIT] = 1;
	if (visited[pos->y][pos->x] || current == WALL || current == EXIT)
		return ;
	visited[pos->y][pos->x] = true;
	if (current == COLLECTIBLE)
		reachable[COLLECTIBLE]++;
	new_pos = (t_pos){pos->x, pos->y - 1};
	depth_first_search(map, &new_pos, visited, reachable);
	new_pos = (t_pos){pos->x, pos->y + 1};
	depth_first_search(map, &new_pos, visited, reachable);
	new_pos = (t_pos){pos->x - 1, pos->y};
	depth_first_search(map, &new_pos, visited, reachable);
	new_pos = (t_pos){pos->x + 1, pos->y};
	depth_first_search(map, &new_pos, visited, reachable);
}

static bool	**init_visited(t_data *d, t_map *map)
{
	bool	**visited;
	size_t	y;

	visited = malloc(sizeof(bool *) * map->y);
	track_allocation(d, visited);
	y = 0;
	while (y < map->y)
	{
		visited[y] = malloc(sizeof(bool) * map->x);
		track_allocation(d, visited[y]);
		ft_memset(visited[y], false, sizeof(bool) * map->x);
		y++;
	}
	return (visited);
}