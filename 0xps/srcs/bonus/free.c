/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:06:51 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 17:05:07 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_s(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while ((*stack) != NULL)
		{
			tmp = *stack;
			(*stack) = (*stack)->next;
			free(tmp);
		}
	}
}

void	free_all(t_stack **stack_a, t_stack **stack_b, int *tab)
{
	free_s(stack_a);
	free_s(stack_b);
	if (tab)
		free(tab);
}
