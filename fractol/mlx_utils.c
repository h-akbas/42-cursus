/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:01:09 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 19:37:55 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void	px_img(t_data *d, int x, int y, int color)
{
	char	*add;

	add = d->img->addr + ((y * d->img->line_len) + x * (d->img->bpp) / 8);
	*(unsigned int *)add = color;
}

t_data	*init_data(void)
{
	t_data	*d;

	d = malloc(sizeof(t_data));
	if (!d)
		return (NULL);
	d->img = malloc(sizeof(t_img));
	if (!d->img)
	{
		free(d);
		return (NULL);
	}
	d->color = malloc(sizeof(t_color));
	if (!d->color)
	{
		free(d->img);
		free(d);
		return (NULL);
	}
	set_value(d);
	return (d);
}

void	set_value(t_data *d)
{
	d->x_scale = 4.0 / WIDTH;
	d->y_scale = 4.0 / HEIGHT;
	d->x_trans = 0;
	d->y_trans = 0;
	d->zoom_x = 2.0;
	d->zoom_y = 2.0;
	d->x_pos = 0.0;
	d->y_pos = 0.0;
	d->max_iter = 60;
	d->pos = 1;
	d->h = 1;
	d->color->r_start = 0;
	d->color->r_end = 255;
	d->color->g_start = 0;
	d->color->g_end = 255;
	d->color->b_start = 0;
	d->color->b_end = 255;
}
