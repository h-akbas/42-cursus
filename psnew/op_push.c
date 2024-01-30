/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 05:43:52 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 07:24:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"
#include "stack.h"
#include <unistd.h>

static void push(t_stack **src, t_stack **dst, bool print, e_op op)
{
    t_stack *src_top;

    if (*src == NULL)
        return;
    src_top = *src;
    *src = src_top->next;
    if (*dst == NULL)
        src_top->next = NULL;
    else
    {
        src_top->next = *dst;
        (*dst)->prev = src_top;
    }
    *dst = src_top;
    if (*src)
        (*src)->prev = NULL;
    if (print)
		print_op(op);
}

void pa(t_table *table, bool print)
{
    push(&table->stack_b, &table->stack_a, print, PA);
}

void pb(t_table *table, bool print)
{
    push(&table->stack_a, &table->stack_b, print, PB);
}

