/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:52:11 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/14 23:11:49 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

void get_height(char *str, t_data *data)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	ft_assert(fd != -1, "Fd error!", data);
	line = get_next_line(fd);
	ft_assert(line, "Empty file!", data);
	data->map_width = ft_strlen(line) - 1;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map_height++;
	}
	close(fd);
}

char	**parse_map(t_data *data, char *str)
{
	char	*line;
	char	**map;
	int		fd;
	int		i;

	fd = open(str, O_RDONLY);
	ft_assert(fd != -1, "Fd error!", data);
	map = ft_calloc(sizeof(char *), data->map_height + 1);
	ft_assert(map, "Malloc error!", data);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		ft_assert(map[i], "Malloc error!", data);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	close(fd);
	return (map);
}