/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:32:03 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/19 00:24:32 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
		argv = split_args(argv[1], ' ');
		assert_not_null(argv);
	}
	init_data(&a, argv + 1, argc == 2);
	assert_not_null(a);
	if (check_sort(a) == 0)
		sort(&a);
	destroy_stack(&a);
	return (EXIT_SUCCESS);
}
