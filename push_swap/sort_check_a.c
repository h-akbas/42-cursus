/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:07:00 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/11 10:57:11 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sort.h"

int	check_rarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = check_access_a(a, c);
	if (i < get_index(b, c))
		i = get_index(b, c);
	return (i);
}

int	check_rrarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (check_access_a(a, c))
		i = get_stack_size(a) - check_access_a(a, c);
	if ((i < (get_stack_size(b) - get_index(b, c))) && get_index(b, c))
		i = get_stack_size(b) - get_index(b, c);
	return (i);
}

int	check_rarrb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (get_index(b, c))
		i = get_stack_size(b) - get_index(b, c);
	i = check_access_a(a, c) + i;
	return (i);
}

int	check_rrarb_a(t_stack *a, t_stack *b, int c)
{
	int	i;

	i = 0;
	if (check_access_a(a, c))
		i = get_stack_size(a) - check_access_a(a, c);
	i = get_index(b, c) + i;
	return (i);
}
