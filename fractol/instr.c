/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 16:26:46 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:21:25 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx-macos/mlx.h"

void	show_instructions(t_data *d)
{
	mlx_clear_window(d->mlx, d->win);
	mlx_string_put(d->mlx, d->win, 220, 200, 0xFFFF00,
		"	Fractol Instructions	");
	mlx_string_put(d->mlx, d->win, 200, 250, 0xFFFFFF,
		"Use MWHEEL to zoom in/out");
	mlx_string_put(d->mlx, d->win, 200, 300, 0xFFFFFF,
		"Use R/T to change Red value");
	mlx_string_put(d->mlx, d->win, 200, 350, 0xFFFFFF,
		"Use G/H to change Green value");
	mlx_string_put(d->mlx, d->win, 200, 400, 0xFFFFFF,
		"Use B/N to change Blue value.");
	mlx_string_put(d->mlx, d->win, 200, 450, 0xFFFFFF,
		"Use ARROWS to move around.");
	mlx_string_put(d->mlx, d->win, 200, 500, 0xFFFFFF,
		"Use Spacebar to close popup");
}
