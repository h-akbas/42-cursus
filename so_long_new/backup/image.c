/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 13:47:54 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 22:30:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

void	create_images(t_data *d, int width, int height)
{
	int	i;
	
	d->img[NULL_BLOCK] = mlx_xpm_file_to_image(d->mlx_ptr, "assets/null.xpm",
			&width, &height);
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
	d->img[IMG_MAX] = NULL;
	i = 1;
	while (i < IMG_MAX)
	{
		ft_assert(d->img[i], "Image creation error", d);
		i++;
	}
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

int	render(t_data *data)
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
	return (0);
}
