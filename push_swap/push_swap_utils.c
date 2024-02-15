/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:50:58 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/14 21:09:36 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include "./libft/libft.h"

void	put_error(void)
{
	ft_putendl_fd("Error", 2);
	exit(1);
}

void	check_null(void *ptr)
{
	if (ptr == NULL)
		put_error();
	else
		return ;
}

void	destroy_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}
