/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:06:34 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 17:05:30 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_stack_a(t_stack **stack_a, char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoll(tab[i], stack_a, tab)));
	return (0);
}

void	get_index(t_stack **stack_a, int *tab)
{
	int		i;
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		i = 0;
		while (i < ft_lstsize(*stack_a))
		{
			if (tmp->value == tab[i])
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	choose_algo(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	*tab;

	tab = NULL;
	size = ft_lstsize(*stack_a);
	if (!*stack_a)
		return ;
	else if (size == 2)
		sorting_two_numbers(stack_a);
	else if (size == 3)
		sorting_three_numbers(stack_a);
	else if (size == 5)
		sorting_five_numbers(stack_a, stack_b);
	else
	{
		tab = creating_tab(stack_a);
		sort_int_tab(tab, size);
		get_index(stack_a, tab);
		if (size <= 100)
			sorting_to_hundred(stack_a, stack_b, size);
		else
			sorting(stack_a, stack_b, size);
	}
	free(tab);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (ft_init(&stack_a, argc, argv) == 1)
		return (1);
	if (is_sorted(&stack_a) == 1)
		return (1);
	choose_algo(&stack_a, &stack_b);
	free_s(&stack_a);
	free_s(&stack_b);
}
