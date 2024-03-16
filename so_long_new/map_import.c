/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_import.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:38:16 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 18:45:20 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/fcntl.h>
#include <unistd.h>

static void	set_width_height(t_data *d, t_map *map, char *map_path);
static void	update_width_height(t_map *map, char *buffer, ssize_t bytes_read);
static void	init_map_grid(t_data *d, t_map *map, int width, int height);
static void	map_file_to_map_grid(t_data *d, t_map *map, char *map_path);

void	import_map(t_data *d, char *map_path)
{
	set_width_height(d, d->map, map_path);
	init_map_grid(d, d->map, d->map->x, d->map->y);
	map_file_to_map_grid(d, d->map, map_path);
}

static void	set_width_height(t_data *d, t_map *map, char *map_path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(map_path, O_RDONLY);
    ft_assert(fd >= 0, strerror(errno), d);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			read_error(d, "read function failed", fd);
		update_width_height(map, buffer, bytes_read);
	}
	if (map->x > 0)
		map->y++;
	close(fd);
}

static void	update_width_height(t_map *map, char *buffer, ssize_t bytes_read)
{
	int	i;

	i = 0;
	while (map->y == 0 && buffer[i] != '\n' && i < bytes_read)
	{
		map->x++;
		i++;
	}
	while (i < bytes_read)
		if (buffer[i++] == '\n')
			map->y++;
}

static void	init_map_grid(t_data *d, t_map *map, int width, int height)
{
	int	y;

	map->grid = malloc(height * sizeof(t_block *));
	track_allocation(d, map->grid);
	y = 0;
	while (y < height)
	{
		map->grid[y] = malloc(width * sizeof(t_block));
		track_allocation(d, map->grid[y]);
		y++;
	}
}

static void	map_file_to_map_grid(t_data *d, t_map *map, char *map_path)
{
	int		fd;
	size_t	y;
	int		width;
	char	*line;

	width = map->x;
	fd = open(map_path, O_RDONLY);
    ft_assert(fd >= 0, strerror(errno), d);
	y = 0;
	while (y < map->y)
	{
		if ((line = get_next_line(fd)) == NULL)
			read_error(d, "get_next_line failed", fd);
		cut_nl(line);
		if ((int)ft_strlen(line) != width)
			read_error(d, "Inconsistent line length in map file", fd);
		line_to_grid(map->grid, line, y);
		free(line);
		y++;
	}
	close(fd);
}