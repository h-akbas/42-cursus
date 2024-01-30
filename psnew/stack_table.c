/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 03:47:05 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 06:40:40 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "arg.h"
#include <stdlib.h>

int find_minimum_index(t_stack *stack)
{
	int min_index;

	min_index = stack->index;
	while (stack)
	{
		if (stack->index < min_index)
			min_index = stack->index;
		stack = stack->next;
	}
	return (min_index);
}
void	set_table(t_table **table, int ac, char **av)
{
	t_stack	*new;
	char	**args;
	int		i;

	*table = (t_table *)malloc(sizeof(t_table));
	(*table)->stack_a = NULL;
	(*table)->stack_b = NULL;
	(*table)->stack_size = 0;
	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = av + 1;
	i = 0;
	while (args[i])
	{
		new = create_new_stack(ft_atoi(args[i]));
		append_stack(&(*table)->stack_a, new);
		(*table)->stack_size++;
		i++;
	}
	if (ac == 2)
		free_args(args);
}
