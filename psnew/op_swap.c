/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 07:32:12 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 07:32:35 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "stack.h"
#include <stddef.h>

static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
}

void		sa(t_table *table, bool print)
{
	swap(table->stack_a);
	if (print)
		print_op(SA);
}

void		sb(t_table *table, bool print)
{
	swap(table->stack_b);
	if (print)
		print_op(SB);
}

void		ss(t_table *table, bool print)
{
	sa(table, false);
	sb(table, false);
	if (print)
		print_op(SS);
}

