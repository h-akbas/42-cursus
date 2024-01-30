/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 00:32:29 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 06:36:44 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*push_to_stack(t_table *table, int target_stack)
{
	if (target_stack == STACK_B)
	{
		pa(table, 1);
		return table->stack_b;
	}
	else if (target_stack == STACK_A)
	{
		pb(table, 1);
		return table->stack_a;
	}
	return table->stack_a;
}

int find_index_position(t_stack *stack, int index)
{
    int pos;

	pos = 0;
    while (stack->index != index)
    {
        stack = stack->next;
        pos++;
    }
    return pos;
}
int	push_and_track_position(t_table *table, t_stack **stack, int index, int *pos)
{
	*stack = push_to_stack(table, STACK_B);
	*pos = find_index_position(*stack, index);
	return (1);
}

int find_max_index(t_stack *stack)
{
    int max_index = stack->index;
    while (stack)
    {
        if (stack->index > max_index)
            max_index = stack->index;
        stack = stack->next;
    }
    return max_index;
}
void find_nearest_index(t_table *table, int *index, int *close_index, int *pos)
{
    *index = find_max_index(table->stack_b);
    *close_index = *index - 1;
    *pos = find_index_position(table->stack_b, *index);
}
