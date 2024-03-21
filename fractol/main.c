/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:36:09 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/18 00:06:16 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx-macos/mlx.h"
#include <unistd.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	*d;

	d = NULL;
	if (argc != 2)
	{
		write(2, USAGE, ft_strlen(USAGE));
		return (EXIT_FAILURE);
	}
	else
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 11))
			mandelbrot(d);
		else if (!ft_strncmp(argv[1], "julia", 5))
			julia(d);
		else if (!ft_strncmp(argv[1], "burningship", 11))
			burning_ship(d);
		else
		{
			write(2, USAGE, ft_strlen(USAGE));
			return (EXIT_FAILURE);
		}
	}
}
