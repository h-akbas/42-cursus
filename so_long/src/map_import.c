/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:26:52 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:47:15 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/map.h"
#include "../libs/get_next_line/get_next_line.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

static void	set_dimension(t_data *data, t_map *map, char *map_path);
static void	update_dimension(t_map *map, char *buffer, ssize_t bytes_read);
static void	init_map_grid(t_data *data, t_map *map, int width, int height);
static void	map_file_to_map_grid(t_data *data, t_map *map, char *map_path);

void	import_map(t_data *data, char *map_path)
{
	set_dimension(data, data->map, map_path);
	init_map_grid(data, data->map, data->map->width, data->map->height);
	map_file_to_map_grid(data, data->map, map_path);
}

static void	set_dimension(t_data *data, t_map *map, char *map_path)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		put_error(data, strerror(errno));
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
			reading_error(data, "read function failed", fd);
		update_dimension(map, buffer, bytes_read);
	}
	if (map->width > 0)
		map->height++;
	close(fd);
}

static void	update_dimension(t_map *map, char *buffer, ssize_t bytes_read)
{
	int	i;

	i = 0;
	while (map->height == 0 && buffer[i] != '\n' && i < bytes_read)
	{
		map->width++;
		i++;
	}
	while (i < bytes_read)
		if (buffer[i++] == '\n')
			map->height++;
}

static void	init_map_grid(t_data *data, t_map *map, int width, int height)
{
	int	y;

	map->grid = malloc(height * sizeof(t_block *));
	track_allocation(data, map->grid);
	y = 0;
	while (y < height)
	{
		map->grid[y] = malloc(width * sizeof(t_block));
		track_allocation(data, map->grid[y]);
		y++;
	}
}

static void	map_file_to_map_grid(t_data *data, t_map *map, char *map_path)
{
	int		fd;
	int		y;
	int		width;
	char	*line;

	width = map->width;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		put_error(data, strerror(errno));
	y = 0;
	while (y < map->height)
	{
		if (get_next_line(fd, &line) == EXIT_FAILURE)
			reading_error(data, "get_next_line failed", fd);
		cut_nl(line);
		if ((int)ft_strlen(line) != width)
			reading_error(data, "Inconsistent line length in map file", fd);
		line_to_grid(map->grid, line, y);
		free(line);
		y++;
	}
	close(fd);
}
