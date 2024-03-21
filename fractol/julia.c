/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:36:10 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:21:26 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx-macos/mlx.h"

int	julia_iter(t_complex c, int x, int y, t_data *d)
{
	t_complex	result;
	t_complex	z;

	d->iter = 0;
	z.r = (x * d->x_scale) - d->zoom_x;
	z.i = (y * d->y_scale) - d->zoom_y;
	while ((z.r * z.r) + (z.i * z.i) < 4 && d->iter < d->max_iter)
	{
		result.r = (z.r * z.r) - (z.i * z.i) + c.r;
		result.i = (2 * z.i * z.r) + c.i;
		z = result;
		d->iter++;
	}
	return (d->iter);
}

void	julia_px(t_data *d)
{
	int			x;
	int			y;
	t_complex	c;

	c.r = d->x_pos;
	c.i = d->y_pos;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			d->iter = julia_iter(c, x, y, d);
			px_img(d, x, y, color_pixel(d));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img->ptr, 0, 0);
	mlx_string_put(d->mlx, d->win, 5, 0, 0xFFFFFF,
		"Press SPACE for instruction");
	mlx_string_put(d->mlx, d->win, 5, 20, 0xFFFFFF,
		"Use RMB to change Julia");
	if (d->h == -1)
		show_instructions(d);
}
