/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:32:03 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/01 22:44:16 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = parse_data(argc, argv);
	if (!a || check_duplication(a))
	{
		destroy_stack(&a);
		put_error();
	}
	if (!check_sort(a))
		sort(&a);
	destroy_stack(&a);
	return (0);
}
