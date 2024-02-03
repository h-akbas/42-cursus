/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:58:56 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 15:55:28 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "sort.h"

static void	create_sort_layout(t_table *table, int num_partitions,
								int partition_size);
static void	sort_three(t_table *table);
static void optisort(t_table *table);
static void custom_sort(t_table *table);

void sort_all(t_table *table)
{
	if (table->stack_size < 3)
		sa(table, 1);
	else if (table->stack_size < 4)
		sort_three(table);
	else if (table->stack_size < 30)
	{
		create_sort_layout(table, 1, (table->stack_size - 3));
		sort_three(table);
		optisort(table);
	}
	else
		custom_sort(table);
}
static void create_sort_layout(t_table *table, int num_partitions, int partition_size)
{
	int	key_number;
	int	rotation_hold;

	key_number = partition_size * num_partitions;
	rotation_hold = 0;
	while (has_index_lower_than(table->stack_a, key_number))
	{
		if (table->stack_a->index < key_number)
			process_stack_a(table, rotation_hold, key_number, partition_size);
		else
		{
			if (rotation_hold == 1)
				rr(table, 1);
			else
				ra(table, 1);
		}
	}
}

static void	sort_three(t_table *table)
{
	t_stack	*stack;
	int		a;
	int		b;
	int		c;

	stack = table->stack_a;
	a = stack->value;
	b = stack->next->value;
	c = stack->next->next->value;
	if (a > b && a > c)
	{
		if (b > c)
			sa(table, 1);
		ra(table, 1); //o: sa_ra(table, 1);
	}
	else if (b > a && b > c)
	{
		if (a > c)
			sa(table, 1); //o: ra(table, 1);
		else
			rra(table, 1); //o: sa_ra(table, 0);
	}
	else if (a > b)
		sa(table, 1);
}

static void optisort(t_table *table)
{
	int index;
	int close_index;
	int position;
	int swap;
	t_stack *stack;

	stack = table->stack_b;
	while (stack)
	{
		find_nearest_index(table, &index, &close_index, &position);
		swap = 0;
		while (stack->index != index)
		{
			if (stack->index == close_index)
				swap = push_and_track_position(table, &stack, index, &position);
			best_rr(table, position, STACK_B);
		}
		stack = push_to_stack(table, STACK_B);
		if (swap)
			sa(table, 1);
	}
}

static void custom_sort(t_table *table)
{
	int num_partitions;
	int partition_size;
	int i;

	num_partitions = 5;
	partition_size = table->stack_size / num_partitions;
	i = 0;
	while (i < num_partitions)
	{
		create_sort_layout(table, i, partition_size);
		i++;
	}
	sort_three(table);
	optisort(table);
}

