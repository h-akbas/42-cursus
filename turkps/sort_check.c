/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:23:50 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/02 00:58:11 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "sort.h"
#include "stack.h"

int	check_rarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = check_access_b(b, c);
	if (i < get_index(a, c))
		i = get_index(a, c);
	return (i);
}


int	check_rrarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (check_access_b(b, c))
		i = get_stack_size(b) - check_access_b(b, c);
	if ((i < (get_stack_size(a) - get_index(a, c))) && get_index(a, c))
		i = get_stack_size(a) - get_index(a, c);
	return (i);
}

int	check_rrarb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index(a, c))
		i = get_stack_size(a) - get_index(a, c);
	i = check_access_b(b, c) + i;
	return (i);
}

int	check_rarrb(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (check_access_b(b, c))
		i = get_stack_size(b) - check_access_b(b, c);
	i = get_index(a, c) + i;
	return (i);
}
