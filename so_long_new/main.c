/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:59:53 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/14 23:13:03 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
    t_data  *data;
    
    data = ft_calloc(sizeof(t_data), 1);
    ft_assert(data != NULL, "Allocation Error!", NULL);
    ft_assert(argc == 2, "Invalid number of arguments!", NULL);
	init_game(argv[1], data);
	return (0);
}