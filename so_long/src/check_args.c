/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:07:35 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/12 23:12:46 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/libft/libft.h"

void	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nUsage: ./so_long [map.ber]\n", 2);
		exit(1);
	}
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
	{
		ft_putstr_fd("Error\nMap file must be a .ber file\n", 2);
		exit(1);
	}
	return ;
}
