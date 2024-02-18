/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:38:29 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/17 12:03:33 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdlib.h>

t_stack	*create_new_stack(int content)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	assert_not_null(new_stack);
	new_stack->nbr = content;
	new_stack->next = NULL;
	return (new_stack);
}

void	append_stack(t_stack **stack, t_stack *stack_new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = stack_new;
	else
		(get_last_item(*stack))->next = stack_new;
}
