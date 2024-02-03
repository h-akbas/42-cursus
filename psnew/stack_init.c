/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:33:23 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 08:06:31 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp && temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

void	assign_indexes(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*top;
	int		i;



	i = 0;
	top = stack;
	while (stack)
	{
		temp = top;
		while(temp)
		{
			if (temp->value < stack->value)
				i++;
			temp=temp->next;
		}
		stack->index = i;
		stack = stack->next;
		i = 0;
	}
}

