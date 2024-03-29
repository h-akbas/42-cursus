/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:15:54 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:49:28 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
#include "../inc/gfx.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argv[1]);
	display_game(&data);
	init_game(&data);
	return (EXIT_SUCCESS);
}
