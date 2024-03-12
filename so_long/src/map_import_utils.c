/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_import_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:44:40 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:45:09 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include <errno.h>
#include <string.h>
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
		return (EMPTY);
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

void	reading_error(t_data *d, char *description, int fd)
{
	ssize_t	ret;

	ret = close(fd);
	if (ret == -1)
		put_error(d, strerror(errno));
	put_error(d, description);
}
