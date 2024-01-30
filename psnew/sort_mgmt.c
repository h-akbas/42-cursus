/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 06:43:34 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 07:20:53 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "stack.h"

void rotate_or_push_b(t_table *table, int rotation_hold, int key_number,
															int partition_size)
{
	if (rotation_hold == 1)
	{
		rr(table, 1);
	}
	else
	{
		ra(table, 1);
		rotation_hold = 0;
	}
	if (table->stack_a->index < (key_number - (partition_size / 2))) {
		pb(table, 1);
		rotation_hold = 1;
	}
	else
	{
		pb(table, 1);
	}
}

void process_stack_a(t_table *table, int rotation_hold, int key_number, int partition_size)
{
	if (table->stack_a->index < key_number)
		rotate_or_push_b(table, rotation_hold, key_number, partition_size);
	else
	{
		if (rotation_hold == 1)
			rr(table, 1);
		else
			ra(table, 1);
	}
}

void rotate_for_best_rr(t_table *box, int pos, int side)
{
    int size;

    if (side == STACK_A)
    {
        size = get_stack_len(box->stack_a);
    }
    else
    {
        size = get_stack_len(box->stack_b);
    }

    if (pos > (size / 2))
        if (side == STACK_A)
            rra(box, 1);
        else
            rrb(box, 1);
    else
        if (side == STACK_A)
            ra(box, 1);
        else
            rb(box, 1);
}

void best_rr(t_table *box, int pos, int side)
{
    int condition = (pos == 0);

    if (condition)
        return;

    rotate_for_best_rr(box, pos, side);
}


