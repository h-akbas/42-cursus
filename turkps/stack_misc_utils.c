/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_misc_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:47:42 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/01 21:49:31 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stack.h"

int	check_sort(t_stack *stack)
{
	int	tmp;

	if (!stack)
		return (0);
	tmp = stack->nbr;
	while (stack)
	{
		if (tmp > stack->nbr)
			return (0);
		tmp = stack->nbr;
		stack = stack->next;
	}
	return (1);
}

int	check_duplication(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_access_b(t_stack *stack_b, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push > stack_b->nbr && nbr_push < get_last_item(stack_b)->nbr)
		i = 0;
	else if (nbr_push > get_max(stack_b) || nbr_push < get_min(stack_b))
		i = get_index(stack_b, get_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->nbr < nbr_push || tmp->nbr > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	check_access_a(t_stack *stack_a, int nbr_push)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	if (nbr_push < stack_a->nbr && nbr_push > get_last_item(stack_a)->nbr)
		i = 0;
	else if (nbr_push > get_max(stack_a) || nbr_push < get_min(stack_a))
		i = get_index(stack_a, get_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->nbr > nbr_push || tmp->nbr < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
