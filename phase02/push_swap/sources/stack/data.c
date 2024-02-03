/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:00:15 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 22:38:15 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"
#include <stdlib.h>

static void	create_stack(t_data *data, t_stack *stack, int size)
{
	stack->arr = (int *)malloc(sizeof(int) * size);
	if (!stack->arr)
		put_error(data);
	stack->top = 0;
	stack->bottom = 0;
	stack->size = size;
	ft_bzero(stack->arr, sizeof(int) * size);
}

void		parse_data(t_data *data, int argc, char **argv, bool reporting)
{
	--argc;
	create_stack(data, data->a, argc);
	create_stack(data, data->b, argc);
	fill_stack(data, data->a, argc, ++argv);
	data->reporting = reporting;
	data->instructions = NULL;
}

bool	check_sorted(t_data *data)
{
	int	i;
	int rank;
	
	i = data->a->top;
	rank = 1;
	while (rank <= data->a->size)
	{
		if (data->a->arr[i] != rank)
			return (false);
		rank++;
		i = get_index_below(data->a, data->a->size);
	}
	return (true);
}

void    free_all(t_data *data)
{
    if (data->a->arr)
        free(data->a->arr);
    if (data->b->arr)
        free(data->b->arr);
    if (data->instructions)
        free(data->instructions);
}
void	put_error(t_data *data)
{
    free_all(data);
    ft_putendl_fd("Error", 2);
    exit(EXIT_FAILURE);
}
