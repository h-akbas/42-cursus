/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:07:14 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 06:39:01 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack	*create_new_stack(int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->index = 0;
	new_stack->next = NULL;
	new_stack->prev = NULL;
	return (new_stack);
}

int	get_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
t_stack	*find_last_node(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}
void	append_stack(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (*stack)
	{
		last = find_last_node(*stack);
		last->next = new;
		new->prev = last;
	}
	else
		*stack = new;
}
bool	has_index_lower_than(t_stack *stack, int index)
{
	while (stack)
	{
		if (stack->index < index)
			return (true);
		stack = stack->next;
	}
	return (false);
}
