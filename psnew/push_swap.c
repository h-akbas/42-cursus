/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:29:53 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 03:33:56 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_table	*table;

	if (argc < 2)
		return (0);
	if (!is_valid_args(argc, argv))
		print_error(-1);
	set_table(&table, argc, argv);
	if (is_sorted(table->stack_a))
		return (0);
	assign_indexes(table->stack_a);
	sort_all(table);
	free_table(table);
	return (0);
}
