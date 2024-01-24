/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:00:15 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 19:15:39 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static void	create_stack(t_data *data, t_stack *stack, int size);

void		parse_data(t_data *data, int argc, char **argv, bool reporting)
{
	--argc;
	create_stack(data, &data->a, argc);
	create_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, ++argv);
	data->reporting = reporting;
	data->instructions = NULL;
}

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