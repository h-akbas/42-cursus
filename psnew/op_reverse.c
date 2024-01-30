/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 07:30:03 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 07:30:47 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "stack.h"
#include <stddef.h>

static void	reverse(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = stack;
	stack->prev = tmp;
	stack = stack->next;
	stack->prev->next = NULL;
	stack->prev = NULL;
}

void		rra(t_table *table, bool print)
{
	reverse(table->stack_a);
	if (print)
		print_op(RRA);
}

void		rrb(t_table *table, bool print)
{
	reverse(table->stack_b);
	if (print)
		print_op(RRB);
}
void rrr(t_table *table, bool print)
{
	rra(table, false);
	rrb(table, false);
	if (print)
		print_op(RRR);
}
