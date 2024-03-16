/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:51:02 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 23:09:23 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

static void render_image(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	while (d->map->grid[++y])
	{
		x = -1;
		while (d->map->grid[y][++x])
		{
			if (d->map->grid[y][x] == '1')
				mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[WALL], x * WIDTH, y * HEIGHT);
			else if (d->map->grid[y][x] == 'C')
				mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[COLLECTIBLE], x * WIDTH, y * HEIGHT);
			else if (d->map->grid[y][x] == 'E')
				mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[EXIT], x * WIDTH, y * HEIGHT);
			else
				mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[FLOOR], x * WIDTH, y * HEIGHT);
		}
	}
}

void	create_images(t_data *d, int width, int height)
{
	d->img[NULL_BLOCK] = NULL;
	d->img[PLAYER] = mlx_xpm_file_to_image(d->mlx_ptr, PLAYER_IMG, &width, &height);
	d->img[EXIT] = mlx_xpm_file_to_image(d->mlx_ptr, EXIT_IMG, &width, &height);
	d->img[COLLECTIBLE] = mlx_xpm_file_to_image(d->mlx_ptr, COLLECTIBLE_IMG, &width, &height);
	d->img[FLOOR] = mlx_xpm_file_to_image(d->mlx_ptr, FLOOR_IMG, &width, &height);
	d->img[WALL] = mlx_xpm_file_to_image(d->mlx_ptr, WALL_IMG, &width, &height);
}

int	render(t_data *data)
{
	render_image(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img[PLAYER], data->pos.x * WIDTH, data->pos.y);
	return (0);
}