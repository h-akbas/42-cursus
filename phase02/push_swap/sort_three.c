/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:12:41 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/11 10:57:44 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

void	sort_three(t_stack **stack_a)
{
	if (get_min(*stack_a) == (*stack_a)->nbr)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (get_max(*stack_a) == (*stack_a)->nbr)
	{
		ra(stack_a, 0);
		if (!check_sort(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (get_index(*stack_a, get_max(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
