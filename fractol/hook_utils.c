/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:58:24 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:21:23 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx-macos/mlx.h"
#include <stdlib.h>

int	get_mouse_pos(int x, int y, t_data *data)
{
	if (data->pos == 1)
	{
		if ((x < WIDTH && x >= 0) || (y < HEIGHT && y >= 0))
		{
			data->x_pos = (x * data->x_scale) - data->zoom_x;
			data->y_pos = (y * data->y_scale) - data->zoom_y;
		}
		julia_px(data);
	}
	return (0);
}

void	handle_key_hook(int keycode, t_data *data)
{
	if (keycode == 15)
		data->color->r_end -= 100;
	else if (keycode == 5)
		data->color->g_end -= 100;
	else if (keycode == 11)
		data->color->b_end -= 100;
	else if (keycode == 17)
		data->color->r_end += 100;
	else if (keycode == 4)
		data->color->g_end += 100;
	else if (keycode == 45)
		data->color->b_end += 100;
	else if (keycode == 124)
		data->zoom_x -= 20 * data->x_scale;
	else if (keycode == 123)
		data->zoom_x += 20 * data->x_scale;
	else if (keycode == 126)
		data->zoom_y += 20 * data->y_scale;
	else if (keycode == 125)
		data->zoom_y -= 20 * data->y_scale;
}

void	handle_mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 5)
	{
		data->max_iter += 20;
		data->x_scale *= 0.5;
		data->y_scale *= 0.5;
		data->zoom_x = data->zoom_x - (x * data->x_scale);
		data->zoom_y = data->zoom_y - (y * data->y_scale);
	}
	else if (button == 4)
	{
		data->max_iter -= 20;
		data->x_scale *= 2;
		data->y_scale *= 2;
		data->zoom_x = data->zoom_x + (x * data->x_scale);
		data->zoom_y = data->zoom_y + (y * data->y_scale);
	}
}

int	handle_cross_sign(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free(data->color);
	free(data->img);
	free(data);
	exit(0);
}

int	handle_no_hook(t_data *data)
{
	if (data->fractal == 1)
		mandel_px(data);
	else if (data->fractal == 2)
		julia_px(data);
	else if (data->fractal == 3)
		burning_px(data);
	return (1);
}
