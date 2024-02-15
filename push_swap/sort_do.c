/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_do.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:16:01 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/14 21:34:27 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "operation.h"

int	do_rarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && check_access_b(*b, c) > 0)
			rr(a, b);
		while ((*a)->nbr != c)
			ra(a);
		while (check_access_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && check_access_a(*a, c) > 0)
			rr(a, b);
		while ((*b)->nbr != c)
			rb(b);
		while (check_access_a(*a, c) > 0)
			ra(a);
		pa(a, b);
	}
	return (-1);
}

int	do_rrarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c && check_access_b(*b, c) > 0)
			rrr(a, b);
		while ((*a)->nbr != c)
			rra(a);
		while (check_access_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while ((*b)->nbr != c && check_access_a(*a, c) > 0)
			rrr(a, b);
		while ((*b)->nbr != c)
			rrb(b);
		while (check_access_a(*a, c) > 0)
			rra(a);
		pa(a, b);
	}
	return (-1);
}

int	do_rrarb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			rra(a);
		while (check_access_b(*b, c) > 0)
			rb(b);
		pb(a, b);
	}
	else
	{
		while (check_access_a(*a, c) > 0)
			rra(a);
		while ((*b)->nbr != c)
			rb(b);
		pa(a, b);
	}
	return (-1);
}

int	do_rarrb(t_stack **a, t_stack **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->nbr != c)
			ra(a);
		while (check_access_b(*b, c) > 0)
			rrb(b);
		pb(a, b);
	}
	else
	{
		while (check_access_a(*a, c) > 0)
			ra(a);
		while ((*b)->nbr != c)
			rrb(b);
		pa(a, b);
	}
	return (-1);
}
