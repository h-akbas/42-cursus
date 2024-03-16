/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_main_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 14:57:49 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 17:21:13 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "so_long.h"
#include "mlx/mlx.h"

void	ft_assert(bool condition, char *message, t_data *data)
{
	if (!condition)
	{
		free_data(data);
		ft_putendl_fd("Error: ", STDERR_FILENO);
		ft_putendl_fd(message, STDERR_FILENO);
		exit (EXIT_FAILURE);
	}
}

static void	destroy_images(t_data *data)
{
	int	i;

	i = 1;
	while (data->img[i])
	{
		mlx_destroy_image(data->mlx_ptr, data->img[i]);
		i++;
	}
}

static void	destroy_map(char **map)
{
	if (map)
	{
		while (*map)
		{
			free(*map);
			map++;
		}
		free(map);
	}
}

//could be problematic
void	clean_exit(t_data *data)
{
	if (!data)
		return ;
	destroy_map(data->map);
	destroy_images(data);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
	exit(EXIT_FAILURE);
}
