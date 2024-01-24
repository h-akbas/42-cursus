/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:21:40 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/05 12:46:06 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rb_or_rrb(t_stack **stack_b, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_b;
	while (tmp)
	{
		if (tmp->index == size)
			break ;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	sorting_three_numbers(t_stack **stack_a)
{
	if ((*stack_a)->value >= (*stack_a)->next->value
		&& (*stack_a)->next->value <= (*stack_a)->next->next->value
		&& (*stack_a)->value <= (*stack_a)->next->next->value)
		ft_sa(stack_a);
	else if ((*stack_a)->value > (*stack_a)->next->value
		&& (*stack_a)->next->value > (*stack_a)->next->next->value)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if ((*stack_a)->value >= (*stack_a)->next->value
		&& (*stack_a)->next->value <= (*stack_a)->next->next->value
		&& (*stack_a)->value >= (*stack_a)->next->next->value)
		ft_ra(stack_a);
	else if ((*stack_a)->value <= (*stack_a)->next->value
		&& (*stack_a)->next->value >= (*stack_a)->next->next->value
		&& (*stack_a)->value <= (*stack_a)->next->next->value)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if ((*stack_a)->value <= (*stack_a)->next->value
		&& (*stack_a)->next->value >= (*stack_a)->next->next->value
		&& (*stack_a)->value >= (*stack_a)->next->next->value)
		ft_rra(stack_a);
}

int	find_min(t_stack *stack_a)
{
	int	min;

	min = stack_a->value;
	while (stack_a)
	{
		if (stack_a->value < min)
			min = stack_a->value;
		stack_a = stack_a->next;
	}
	return (min);
}

void	push_smallest_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		min;
	int		min_index;

	tmp = *stack_a;
	min = find_min(*stack_a);
	min_index = get_index_of_min(&tmp);
	if (min_index > ft_lstsize(*stack_a) / 2)
	{
		while ((*stack_a)->value != min)
			ft_rra(stack_a);
	}
	else
	{
		while ((*stack_a)->value != min)
			ft_ra(stack_a);
	}
	ft_pb(stack_a, stack_b);
}

void	sorting_five_numbers(t_stack **stack_a, t_stack **stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	sorting_three_numbers(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}
