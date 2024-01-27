/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:54:43 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/27 18:22:36 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

static void	push(t_stack **dest, t_stack **src)
{
	t_stack	*new;

	if (*src == NULL)
		return ;
	new = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	new->prev = NULL;
	if (NULL == *dest)
	{
		*dest = new;
		new->next = NULL;
	}
	else
	{
		new->next = *dest;
		new->next->prev = new;
		*dest = new;
	}
}

void	pa(t_stack **a, t_stack **b, bool checker)
{
	push(a, b);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, bool checker)
{
	push(b, a);
	if (!checker)
		write(1, "pb\n", 3);
}
