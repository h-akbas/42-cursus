/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:15:14 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/15 00:08:21 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

static void is_rectangle(t_data *data);
static int check_elements(t_data *data, t_chk *checker);
static int check_walls(t_data *data, t_chk *checker);
static int check_path(t_data *data, t_chk *checker);

int check_map(t_data *data)
{
	t_chk	*checker;

	is_rectangle(data);
	checker = ft_calloc(sizeof(t_chk), 1);
	ft_assert(checker, "Checker malloc error!", data);
	ft_assert(!check_elements(data, checker), "Invalid map elements!", data);
	ft_assert(!check_walls(data, checker), "Invalid map walls!", data);
	ft_assert(!check_path(data, checker), "Invalid path!", data);
    return (1);
}

static void is_rectangle(t_data *data)
{
	int	width;
	int	height;
	int	i;
	
	width = data->map_width;
	height = 0;
	i = 0;
	while (data->map[height])
	{
		i = 0;
		while (data->map[height][i] && data->map[height][i] != '\n')
			i++;
		ft_assert(i == width, "Map is not rectangle!", data);
		height++;
	}
}

static int check_elements(t_data *data, t_chk *checker)
{
	checker->i = -1;
	while (data->map[++checker->i])
	{
		checker->j = -1;
		while (data->map[checker->i][++checker->j])
		{
			if (!is_valid_char(data->map[checker->i][checker->j]))
				return (free(checker), 0);
			if (data->map[checker->i][checker->j] == 'P')
				checker->p_count++;
			if (data->map[checker->i][checker->j] == 'E')
				checker->e_count++;
			if (data->map[checker->i][checker->j] == 'C')
				checker->c_count++;
		}
	}
	if (checker->p_count != 1 || checker->c_count < 1 || checker->e_count != 1)
		return (free(checker), 0);
	return (free(checker), 1);
}

static int check_walls(t_data *data, t_chk *checker)
{
	checker->i = 0;
	checker->j = 0;
	while(data->map[checker->i][checker->j] != '\n')
		if (data->map[checker->i][checker->j++] != '1')
			return (0);
	checker->j = 0;
	checker->i = data->map_height - 1;
	while (data->map[checker->i][checker->j] != '\0')
		if (data->map[checker->i][checker->j++] != '1')
			return (0);
	checker->i = 0;
	while (data->map[checker->i])
	{
		if (data->map[checker->i][checker->j - 1] != '1')
			return (0);
		if (data->map[checker->i++][0] != '1')
			return (0);
	}
	return (1);
}

static int check_path(t_data *data, t_chk *checker)
{
	get_player_loc(data);
	find_path(data, data->pl_x, data->pl_y);
	if (data->coll_chk != data->coll)
	{
		ft_putendl_fd("Collectible error!", stderr);
		return (0);
	}
	if (!data->is_error)
	{
		ft_putendl_fd("Exit error!", stderr);
		return (0);
	}
	return (1);
}