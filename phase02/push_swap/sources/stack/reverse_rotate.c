/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:53:49 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 22:58:05 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		reverse_rotate(t_stack *stack)
{
    if (is_full(stack))
    {
        stack->top = stack->bottom;
        stack->bottom = get_index_above(stack, stack->bottom);
    }
    else
    {
        stack->top = get_index_above(stack, stack->top);
        stack->arr[stack->top] = stack->arr[stack->bottom];
        stack->arr[stack->bottom] = 0;
        stack->bottom = get_index_above(stack, stack->bottom);
    }
}

void		reverse_rotate_a(t_data *data)
{
    reverse_rotate(&data->a);
    if (data->reporting)
        record_instruction(data, rra);
}

void		reverse_rotate_b(t_data *data)
{
    reverse_rotate(&data->b);
    if (data->reporting)
        record_instruction(data, rrb);
}

void		reverse_rotate_ab(t_data *data)
{
    reverse_rotate(&data->a);
    reverse_rotate(&data->b);
    if (data->reporting)
        record_instruction(data, rrr);
}