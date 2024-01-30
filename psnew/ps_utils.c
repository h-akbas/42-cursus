/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:16:45 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 05:40:22 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>



void free_stack(t_stack *stack)
{
	t_stack	*temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}



void free_table(t_table *table)
{
	free_stack(table->stack_a);
	free_stack(table->stack_b);
	free(table);
}

void print_error(int status)
{
	write(2, "Error\n", 6);
	exit(status);
}
