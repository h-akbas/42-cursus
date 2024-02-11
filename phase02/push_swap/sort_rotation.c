/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:15:08 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/02 01:10:18 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort.h"

int	get_ba_rotation(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = b;
	i = check_rrarrb_a(a, b, b->nbr);
	while (tmp)
	{
		if (i > check_rarb_a(a, b, tmp->nbr))
			i = check_rarb_a(a, b, tmp->nbr);
		if (i > check_rrarrb_a(a, b, tmp->nbr))
			i = check_rrarrb_a(a, b, tmp->nbr);
		if (i > check_rarrb_a(a, b, tmp->nbr))
			i = check_rarrb_a(a, b, tmp->nbr);
		if (i > check_rrarb_a(a, b, tmp->nbr))
			i = check_rrarb_a(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}

int	get_ab_rotation(t_stack *a, t_stack *b)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = check_rrarrb(a, b, a->nbr);
	while (tmp)
	{
		if (i > check_rarb(a, b, tmp->nbr))
			i = check_rarb(a, b, tmp->nbr);
		if (i > check_rrarrb(a, b, tmp->nbr))
			i = check_rrarrb(a, b, tmp->nbr);
		if (i > check_rarrb(a, b, tmp->nbr))
			i = check_rarrb(a, b, tmp->nbr);
		if (i > check_rrarb(a, b, tmp->nbr))
			i = check_rrarb(a, b, tmp->nbr);
		tmp = tmp->next;
	}
	return (i);
}
