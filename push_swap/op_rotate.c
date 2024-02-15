/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:23:41 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/14 21:33:32 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operation.h"
#include "./libft/libft.h"

void	ra(t_stack **a)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = get_last_item(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = get_last_item(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a || !((*a)->next) || !*b || !((*b)->next))
		return ;
	tmp = *a;
	*a = get_last_item(*a);
	(*a)->next = tmp;
	*a = tmp->next;
	tmp->next = NULL;
	tmp = *b;
	*b = get_last_item(*b);
	(*b)->next = tmp;
	*b = tmp->next;
	tmp->next = NULL;
	ft_putendl_fd("rr", 1);
}
