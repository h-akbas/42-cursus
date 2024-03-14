/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:35:56 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/15 00:03:43 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "so_long.h"

bool	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (true);
	return (false);
}

void	get_player_loc(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[x])
	{
		y = 0;
		while(data->map[x][y])
		{
			if (data->map[x][y] == 'P')
			{
				data->pl_x = x;
				data->pl_y = y;
			}
			if (data->map[x][y] == 'C')
				data->coll_chk++;
			y++;
		}
		x++;
	}
}

void	find_path(t_data *data, int x, int y)
{
	if (data->map[x][y] == '1')
		return ;
	else if (data->map[x][y] == 'C')
		data->coll++;
	else if (data->map[x][y] == 'E')
		data->is_error = true;
	data->map[x][y] = '1';
	find_path(data, x - 1, y);
	find_path(data, x, y - 1);
	find_path(data, x + 1, y);
	find_path(data, x, y + 1);
}