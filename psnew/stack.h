/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:29:57 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 08:25:27 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
#define DATA_H

#include <stdbool.h>

# define INVALID_ERROR 1
# define MEMORY_ERROR 2
# define STACK_A 0
# define STACK_B 1

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_table
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				stack_size;
}					t_table;

void	set_table(t_table **table, int argc, char **argv);
bool	is_sorted(t_stack *stack);
void	assign_indexes(t_stack *stack);
t_stack	*push_to_stack(t_table *table, int target_stack);
int		find_index_position(t_stack *stack, int index);
int		push_and_track_position(t_table *table, t_stack **stack, int index, int *pos);
int		find_max_index(t_stack *stack);
void	find_nearest_index(t_table *table, int *index, int *close_index, int *pos);
t_stack	*create_new_stack(int value);
bool	has_index_lower_than(t_stack *stack, int index);
void	append_stack(t_stack **stack, t_stack *new_stack);
int		get_stack_len(t_stack *stack);
t_stack	*find_last_node(t_stack *head);

#endif
