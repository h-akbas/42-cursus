/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:45:25 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/05 12:46:35 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_tablen(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < ((size) - 1))
	{
		j = 0;
		while (j < ((size) - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_index_of_min(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min_pos;
	int		min;
	int		pos;

	tmp = *stack_a;
	min = find_min(tmp);
	min_pos = 0;
	pos = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == min)
		{
			min_pos = pos;
			break ;
		}
		tmp = tmp->next;
		pos++;
	}
	return (min_pos);
}
