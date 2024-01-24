/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:49:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 22:52:48 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void		rotate(t_stack *stack)
{
    if (is_full(stack))
    {
        stack->bottom = stack->top;
        stack->top = get_index_below(stack, stack->top);
    }
    else
    {
        stack->bottom = get_index_below(stack, stack->bottom);
        stack->arr[stack->bottom] = stack->arr[stack->top];
        stack->arr[stack->top] = 0;
        stack->top = get_index_below(stack, stack->top);
    }
}

void		rotate_a(t_data *data)
{
    rotate(&data->a);
    if (data->reporting)
        record_instruction(data, ra);
}

void		rotate_b(t_data *data)
{
    rotate(&data->b);
    if (data->reporting)
        record_instruction(data, rb);
}

void		rotate_ab(t_data *data)
{
    rotate(&data->a);
    rotate(&data->b);
    if (data->reporting)
        record_instruction(data, rr);
}