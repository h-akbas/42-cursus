/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 07:27:45 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 07:31:13 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "stack.h"
#include <stddef.h>

static void	rotate(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack;
	stack = stack->next;
	stack->prev = NULL;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack->prev;
	stack->prev = tmp;
}

void		ra(t_table *table, bool print)
{
	rotate(table->stack_a);
	if (print)
		print_op(RA);
}

void		rb(t_table *table, bool print)
{
	rotate(table->stack_b);
	if (print)
		print_op(RB);
}

void		rr(t_table *table, bool print)
{
	ra(table, false);
	rb(table, false);
	if (print)
		print_op(RR);
}
