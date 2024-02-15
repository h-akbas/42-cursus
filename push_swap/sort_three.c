/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:12:41 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/14 21:35:02 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

void	sort_three(t_stack **stack_a)
{
	if (get_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (get_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a);
		if (!check_sort(*stack_a))
			sa(stack_a);
	}
	else
	{
		if (get_index(*stack_a, get_max(*stack_a)) == 1)
			rra(stack_a);
		else
			sa(stack_a);
	}
}
