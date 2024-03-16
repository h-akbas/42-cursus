/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_import_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:46:32 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 19:01:04 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>

void	cut_nl(char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
}

t_block	char_to_block(char c)
{
	if (c == '0')
		return (FLOOR);
	else if (c == '1')
		return (WALL);
	else if (c == 'C')
		return (COLLECTIBLE);
	else if (c == 'E')
		return (EXIT);
	else if (c == 'P')
		return (PLAYER);
	else
		return (NULL_BLOCK);
}

void	line_to_grid(t_block **grid, char *line, int raw)
{
	int	i;

	i = 0;
	while (line[i])
	{
		grid[raw][i] = char_to_block(line[i]);
		i++;
	}
}

void	read_error(t_data *d, char *description, int fd)
{
	close(fd);
	ft_assert(false, description, d);
}