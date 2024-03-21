/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:50:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:33:40 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx-macos/mlx.h"
#include "fractol.h"
#include <math.h>


int	burning_iter(t_complex z, int x, int y, t_data *d)
{
	t_complex	result;
	t_complex	c;

	d->iter = 0;
	c.r = x * d->x_scale - d->zoom_x;
	c.i = y * d->y_scale - d->zoom_y;
	while ((z.r * z.r) + (z.i * z.i) < 4 && d->iter < d->max_iter)
	{
		result.r = (fabs(z.r) * fabs(z.r)) - (fabs(z.i) * fabs(z.i));
		result.r += c.r;
		result.i = (2 * fabs(z.i) * fabs(z.r) + c.i);
		z = result;
		d->iter++;
	}
	return (d->iter);
}

void	burning_px(t_data *d)
{
	int			x;
	int			y;
	t_complex	z;

	z.r = 0.0;
	z.i = 0.0;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			d->iter = burning_iter(z, x, y, d);
			if (d->iter == d->max_iter)
				px_img(d, x, y, 0x000000);
			else
				px_img(d, x, y, color_pixel(d));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(d->mlx, d->win, d->img->ptr, 0, 0);
	mlx_string_put(d->mlx, d->win, 5, 0, 0xFFFFFF,
		"Press SPACE for instruction");
	if (d->h == -1)
		show_instructions(d);
}
