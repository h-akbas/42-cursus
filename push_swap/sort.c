/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:00:40 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/14 21:34:46 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"
#include "sort.h"
#include <stddef.h>

static void		sort_until_three(t_stack **stack_a, t_stack **stack_b);
static t_stack	*sort_b(t_stack **stack_a);
static t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b);

void	sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (get_stack_size(*stack_a) == 2)
		sa(stack_a);
	else
	{
		stack_b = sort_b(stack_a);
		stack_a = sort_a(stack_a, &stack_b);
		i = get_index(*stack_a, get_min(*stack_a));
		if (i < get_stack_size(*stack_a) - i)
		{
			while ((*stack_a)->nbr != get_min(*stack_a))
				ra(stack_a);
		}
		else
		{
			while ((*stack_a)->nbr != get_min(*stack_a))
				rra(stack_a);
		}
	}
}

static void	sort_until_three(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (get_stack_size(*stack_a) > 3 && !check_sort(*stack_a))
	{
		tmp = *stack_a;
		i = get_ab_rotation(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == check_rarb(*stack_a, *stack_b, tmp->nbr))
				i = do_rarb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == check_rrarrb(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == check_rarrb(*stack_a, *stack_b, tmp->nbr))
				i = do_rarrb(stack_a, stack_b, tmp->nbr, 'a');
			else if (i == check_rrarb(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarb(stack_a, stack_b, tmp->nbr, 'a');
			else
				tmp = tmp->next;
		}
	}
}

static t_stack	*sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (get_stack_size(*stack_a) > 3 && !check_sort(*stack_a))
		pb(stack_a, &stack_b);
	if (get_stack_size(*stack_a) > 3 && !check_sort(*stack_a))
		pb(stack_a, &stack_b);
	if (get_stack_size(*stack_a) > 3 && !check_sort(*stack_a))
		sort_until_three(stack_a, &stack_b);
	if (!check_sort(*stack_a))
		sort_three(stack_a);
	return (stack_b);
}

static t_stack	**sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*tmp;

	while (*stack_b)
	{
		tmp = *stack_b;
		i = get_ba_rotation(*stack_a, *stack_b);
		while (i >= 0)
		{
			if (i == check_rarb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rarb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == check_rarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == check_rrarrb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarrb(stack_a, stack_b, tmp->nbr, 'b');
			else if (i == check_rrarb_a(*stack_a, *stack_b, tmp->nbr))
				i = do_rrarb(stack_a, stack_b, tmp->nbr, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (stack_a);
}
