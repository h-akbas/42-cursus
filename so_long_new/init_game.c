/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:18:05 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/15 00:17:25 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include "mlx/mlx.h"

static void    check_name(t_data *data, char *map)
{
	char	*name;
	size_t	len;
    
	len = ft_strlen(map);
	ft_assert(ft_strncmp(map + len - 4, ".ber", 4) == 0,
		"Map name error", data);
}

void	init_game(char *map, t_data *data)
{
	check_name(data, map);
	get_height(map, data);
	check_map(data);
	data->map = parse_map(data, map);
	data->mlx_ptr = mlx_init();
	ft_assert(data->mlx_ptr, "Couldn't initiate MLX", data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map_width * WIDTH,
						data->map_height * HEIGHT, "Yummy Mice");
	ft_assert(data->win_ptr, "Couldn't create the window", data);
	create_images(data, WIDTH, HEIGHT);
	render(data);
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_hook(data->win_ptr, 17, 0, win_hook, data);
	mlx_loop(data->mlx_ptr);
}