/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:50:58 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/01 23:22:29 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <unistd.h>

void	put_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	destroy_args(char **args)
{
	char	*tmp;

	if (!args)
		return ;
	while (*args)
	{
		tmp = *args;
		args++;
		free(tmp);
	}
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
