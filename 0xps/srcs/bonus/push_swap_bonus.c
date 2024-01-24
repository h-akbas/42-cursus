/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 22:06:34 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 17:18:17 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_init(t_stack **stack_a, int argc, char **argv)
{
	int		i;
	int		n;
	int		sizetotal;
	char	**tab;

	i = 0;
	sizetotal = 0;
	while (++i < argc)
	{
		tab = ft_split(argv[i], " ", &n);
		if (validate_arg(tab) == 1)
			return (freetab(tab), write(2, "Error\n", 6), 1);
		push_to_stack_a(stack_a, tab);
		sizetotal += n;
		freetab(tab);
	}
	if (has_doubles(stack_a) == 1)
		return (free_s(stack_a), write(2, "Error\n", 6), 1);
	return (0);
}

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

int	*creating_tab(t_stack **stack_a)
{
	int		*tab;
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack_a;
	tab = malloc(sizeof(int) * ft_lstsize(*stack_a));
	while (tmp)
	{
		tab[i] = (tmp)->value;
		i++;
		(tmp) = (tmp)->next;
	}
	return (tab);
}
