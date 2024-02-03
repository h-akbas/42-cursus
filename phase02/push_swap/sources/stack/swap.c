/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:58:40 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 23:03:01 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void		swap(t_stack *stack)
{
    int tmp;
    
    if (stack->arr[get_index_below(stack, stack->top)] == 0)
        return ;
    tmp = stack->arr[get_index_below(stack, stack->top)];
    stack->arr[get_index_below(stack, stack->top)] = stack->arr[stack->top];
    stack->arr[stack->top] = tmp;
}

void		swap_a(t_data *data)
{
    swap(&data->a);
    if (data->reporting)
        record_instruction(data, sa);
}

void		swap_b(t_data *data)
{
    swap(&data->b);
    if (data->reporting)
        record_instruction(data, sb);
}

void		swap_ab(t_data *data)
{
    swap(&data->a);
    swap(&data->b);
    if (data->reporting)
        record_instruction(data, ss);
}
