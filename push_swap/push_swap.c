/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:32:03 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/17 12:03:39 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = parse_data(argc, argv);
	assert_not_null(a);
	if (check_duplication(a) == 1)
	{
		destroy_stack(&a);
		put_error();
	}
	if (check_sort(a) == 0)
		sort(&a);
	destroy_stack(&a);
	return (EXIT_SUCCESS);
}
