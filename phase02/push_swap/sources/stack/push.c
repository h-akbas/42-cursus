/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:40:15 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 22:47:43 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void		push(t_stack *src, t_stack *dest)
{
    int i;
    
    if (is_full(dest))
        return ;
    i = get_index_above(dest, dest->top);
    dest->arr[i] = src->arr[src->top];
    src->arr[src->top] = 0;
    src->top = get_index_below(src, src->top);
}

void		push_a(t_data *data)
{
    push(&data->b, &data->a);
    if (data->reporting)
        record_instruction(data, pa);
}

void		push_b(t_data *data)
{
    push(&data->a, &data->b);
    if (data->reporting)
        record_instruction(data, pb);
}