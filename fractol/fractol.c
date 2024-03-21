/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:41:28 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/18 00:14:43 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx-macos/mlx.h"

void	mandelbrot(t_data *d)
{
	d = init_data();
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Mandelbrot");
	d->img->ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img->addr = mlx_get_data_addr(d->img->ptr, &d->img->bpp,
			&d->img->line_len, &d->img->endian);
	d->fractal = 1;
	mlx_hook(d->win, 2, 1L << 0, &key_hook, d);
	mlx_hook(d->win, 4, 1L << 2, &mouse_hook, d);
	mlx_hook(d->win, 17, 0, &handle_cross_sign, d);
	mlx_loop_hook(d->mlx, handle_no_hook, d);
	mlx_loop(d->mlx);
}

void	julia(t_data *d)
{
	d = init_data();
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Julia");
	d->img->ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img->addr = mlx_get_data_addr(d->img->ptr, &d->img->bpp,
			&d->img->line_len, &d->img->endian);
	d->fractal = 2;
	mlx_hook(d->win, 2, 1L << 0, key_hook, d);
	mlx_hook(d->win, 4, 1L << 2, mouse_hook, d);
	mlx_hook(d->win, 6, 1L << 0, get_mouse_pos, d);
	mlx_hook(d->win, 17, 0, handle_cross_sign, d);
	mlx_loop_hook(d->mlx, handle_no_hook, d);
	mlx_loop(d->mlx);
}

void	burning_ship(t_data *d)
{
	d = init_data();
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, "Burning Ship");
	d->img->ptr = mlx_new_image(d->mlx, WIDTH, HEIGHT);
	d->img->addr = mlx_get_data_addr(d->img->ptr, &d->img->bpp,
			&d->img->line_len, &d->img->endian);
	d->fractal = 3;
	mlx_hook(d->win, 2, 1L << 0, key_hook, d);
	mlx_hook(d->win, 4, 1L << 2, mouse_hook, d);
	mlx_hook(d->win, 17, 0, handle_cross_sign, d);
	mlx_loop_hook(d->mlx, handle_no_hook, d);
	mlx_loop(d->mlx);
}
