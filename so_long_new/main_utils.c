/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:07:46 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 23:40:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <unistd.h>

void	track_allocation(t_data *d, void *pointer)
{
	t_list	*new_node;

    ft_assert(pointer != NULL, "Memory allocation error", d);
	new_node = ft_lstnew(pointer);
    ft_assert(new_node != NULL, "Memory allocation error.", d);
	ft_lstadd_front(&d->allocated_pointers, new_node);
}

int	clean_exit(t_data *data, int code)
{
	int	i;

	i = 0;
	if (data->map)
}

void	ft_assert(bool condition, char *message, t_data *data)
{
	if (!condition)
	{
		ft_putendl_fd("Error: ", STDERR_FILENO);
		ft_putendl_fd(message, STDERR_FILENO);
        if (data)
            clean_exit(data);
		exit (EXIT_FAILURE);
	}
}