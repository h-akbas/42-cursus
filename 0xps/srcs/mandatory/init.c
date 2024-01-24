/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:42:54 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 17:05:20 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			return (freetab(tab), free_s(stack_a),
				write(2, "Error\n", 6), 1);
		push_to_stack_a(stack_a, tab);
		sizetotal += n;
		freetab(tab);
	}
	if (has_doubles(stack_a) == 1)
		return (free_s(stack_a), write(2, "Error\n", 6), 1);
	return (0);
}
