/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 23:16:16 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 23:28:48 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/stack.h"

void	sort(t_data *data)
{
    if (data->a->size <= 1 || is_sorted(data))
        return ;
    else if(data->a->size == 3)
        sort_three_a(data);
    else if(data->a->size == 5)
        sort_five_a(data);
    else
        chunk_sort(data);
    optimize(data);
}

void	sort_three(t_data *data)
{
    int first;
    int second;
    int third;

    first = peek_value(data->a, 1);
    second = peek_value(data->a, 2);
    third = peek_value(data->a, 3);
    if (first > second && third > second && third > first)
        swap_a(data);
    else if (second > first && second > third && first > third)
        rotate_a(data);
    else if (second > first && second > third && third > first)
        reverse_rotate_a(data);
    else if (second > first && second > third && third < first)
    {
        swap_a(data);
        rotate_a(data);
    }
    else if (first > second && first > third && second > third)
    {
        swap_a(data);
        reverse_rotate_a(data);
    }
}

void	sort_five(t_data *data)
{
    while (check_size(&data->a) > 3)
    {
        if (peek_value(&data->a, 1) == 1 || peek_value(&data->a, 1) == 2)
            push_b(data);
        else
            rotate_a(data);
    }
    if (peek_value(&data->b, 1) < peek_value(&data->b, 2))
        swap_b(data);
    sort_three(data);
    push_a(data);
    push_a(data);
}