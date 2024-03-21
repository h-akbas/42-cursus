/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:51:07 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:21:24 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx-macos/mlx.h"
#include <stdlib.h>

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free(data->color);
		free(data->img);
		free(data);
		exit(0);
	}
	if (keycode == 49)
		data->h *= -1;
	handle_key_hook(keycode, data);
	handle_no_hook(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->pos *= -1;
		return (0);
	}
	if (button == 5 || button == 4)
		handle_mouse_hook(button, x, y, data);
	handle_no_hook(data);
	return (0);
}
