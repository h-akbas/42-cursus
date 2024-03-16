/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:47:54 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 19:26:01 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"
#include <i386/limits.h>

void	create_images(t_data *d, int width, int height)
{
	int	i;

	i = 1;
	d->img[NULL_BLOCK] = NULL;
	d->img[FLOOR] = mlx_xpm_file_to_image(d->mlx_ptr, "assets/floor.xpm",
			&width, &height);
	d->img[WALL] = mlx_xpm_file_to_image(d->mlx_ptr, "assets/wall.xpm",
			&width, &height);
	d->img[COLLECTIBLE] = mlx_xpm_file_to_image(d->mlx_ptr, "assets/collectible.xpm",
			&width, &height);
	d->img[PLAYER] = mlx_xpm_file_to_image(d->mlx_ptr, "assets/player.xpm",
			&width, &height);
	d->img[EXIT] = mlx_xpm_file_to_image(d->mlx_ptr, "assets/exit.xpm",
			&width,	&height);
	d->img[IMG_MAX - 1] = NULL;
	while (i > NULL_BLOCK && i < IMG_MAX)
		track_allocation(d, d->img[i]);
}

static void	render_image(char elmt, t_data *d, int x, int y)
{
	if (elmt == '1')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[WALL], x * WIDTH,
			y * HEIGHT);
	else if (elmt == 'C')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[COLLECTIBLE], x * WIDTH,
			y * HEIGHT);
	else if (elmt == 'E')
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[EXIT], x * WIDTH,
			y * HEIGHT);
	else if (elmt == 'P' && d->is_player_init == 0)
	{
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[PLAYER], x
			* WIDTH, y * HEIGHT);
		d->is_player_init = 1;
		d->pos.x = x;
		d->pos.y = y;
	}
	else
		mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img[FLOOR], x
			* WIDTH, y * HEIGHT);
}

void	render(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < data->map->y && data->map->grid[y])
	{
		x = 0;
		while (data->map->grid[y][x] != '\n' && data->map->grid[y][x] != '\0')
		{
			render_image(data->map->grid[y][x], data, x, y);
			x++;
		}
		y++;
	}
}
