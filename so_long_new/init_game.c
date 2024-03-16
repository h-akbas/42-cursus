/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:18:05 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 23:14:09 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

static void	check_name(t_data *data, char *map)
{
	size_t	len;

	len = ft_strlen(map);
	ft_assert(ft_strncmp(map + len - 4, ".ber", 4) == 0,
		"Map name error", data);
}

static int win_hook(t_data *data, int key)
{
	clean_exit(data);
	return(key);
}

void	init_game(char *map, t_data *data)
{
	check_name(data, map);
	init_map(data, map);
	data->mlx_ptr = mlx_init();
	ft_assert(data->mlx_ptr, "Couldn't initiate MLX", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->x * WIDTH,
			data->map->y * HEIGHT, "so_long");
	ft_assert(data->win_ptr, "Couldn't create the window", data);
	create_images(data, WIDTH, HEIGHT);
	render(data);
	mlx_hook(data->win_ptr, 2, 0, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, win_hook, data);
	mlx_loop(data->mlx_ptr);
}
