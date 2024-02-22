/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:38:29 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/19 00:21:35 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdlib.h>
#include "./libft/libft.h"

void	append_stack(t_stack **stack, int num)
{
	t_stack	*new_stack;
	t_stack	*last;

	assert_not_null(stack);
	new_stack = malloc(sizeof(t_stack));
	assert_not_null(new_stack);
	new_stack->nbr = num;
	new_stack->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_stack;
		new_stack->prev = NULL;
	}
	else
	{
		last = get_last_item(*stack);
		last->next = new_stack;
		new_stack->prev = last;
	}
}

bool	invalid_input(char *str)
{
	if (ft_strlen(str) == 0 || ft_strlen(str) > 11)
		return (true);
	if (!(*str == '-' || *str == '+' || ft_isdigit(*str)))
		return (true);
	if ((*str == '-' || *str == '+') && !ft_isdigit(str[1]))
		return (true);
	while (*++str)
	{
		if (!ft_isdigit(*str))
			return (true);
		str++;
	}
	return (false);
}

void	destroy_args(char **args)
{
	int	i;

	i = -1;
	if (!args || !*args)
		return ;
	while (args[i])
	{
		free(args[i++]);
	}
	free(args - 1);
}
