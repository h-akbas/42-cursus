/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:57:36 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 22:38:49 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int check_size(t_stack *stack)
{
    if (stack->top == stack->bottom && stack->arr[stack->top] == 0)
        return (0);
    if (stack->top > stack->bottom)
        return ((stack->size - stack->top) + (stack->bottom + 1));
    else
        return (stack->bottom - stack->top + 1);
}

int get_index_above(t_stack *stack, int index)
{
    if (check_size(stack) == 0)
        return (index);
    if (index == 0)
        return (stack->size - 1);
    else
        return (index - 1);
}

int get_index_below(t_stack *stack, int index)
{
    if (check_size(stack) == 0)
        return (index);
    if (index == stack->size - 1)
        return (0);
    else
        return (index + 1);
}

int peek_value(t_stack *stack, int n)
{
    int i;

    i = stack->top;
    while (--n > 0)
        i = get_index_below(stack, i);
    return (stack->arr[i]);
}
bool    is_full(t_stack *stack)
{
    return (stack->size == check_size(stack));
}