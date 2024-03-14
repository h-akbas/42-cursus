/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:06:00 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/14 22:16:27 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "so_long.h"

void ft_assert(bool condition, char *message, t_data *data)
{
    if (!condition)
    {
        ft_putendl_fd("Error: ", stderr);
        ft_putendl_fd(message, stderr);
        clean_exit(data);
    }
}

//could be problematic
void clean_exit(t_data *data)
{
    if (!data)
        return ;
    if (data->map)
        free_map(data->map);
    if (data->mlx_ptr)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    exit(EXIT_FAILURE);
}

