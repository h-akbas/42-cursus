/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:50:58 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/19 00:26:21 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include "./libft/libft.h"
#include <unistd.h>

void	put_error(void)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(1);
}

void	put_error_free(t_stack **a, char **args, bool is_argc_2)
{
	destroy_stack(a);
	if (is_argc_2)
		destroy_args(args);
	put_error();
}

void	assert_not_null(void *ptr)
{
	if (ptr == NULL)
		put_error();
	else
		return ;
}

void	destroy_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (stack == NULL || *stack == NULL)
		return ;
	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}
