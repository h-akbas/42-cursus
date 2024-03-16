/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:35:56 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 16:02:03 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"

bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (true);
	return (false);
}

void	get_map_elements(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				data->pos.x = x;
				data->pos.y = y;
			}
			if (data->map[x][y] == 'C')
				data->coll_chk++;
			y++;
		}
		x++;
	}
}

void	check_map_movements(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	else if (data->map[x][y] == 'C')
		data->coll++;
	else if (data->map[x][y] == 'E')
		data->is_error = true;
	data->map[x][y] = '1';
	check_map_movements(data, x - 1, y);
	check_map_movements(data, x, y - 1);
	check_map_movements(data, x + 1, y);
	check_map_movements(data, x, y + 1);
}
