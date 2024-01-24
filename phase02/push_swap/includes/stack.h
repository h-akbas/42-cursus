/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:57:40 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 19:23:22 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "libft.h"
# include <stdbool.h>

/*TODO: Add requisite libraries*/

typedef struct s_stack
{
	int	*arr;
	int	top;
	int	size;
	int	bottom;
}		t_stack;

typedef struct s_stack_data
{
	t_stack	*a;
	t_stack	*b;
	t_list	*instructions;
	bool	reporting;
}			t_data;

enum		e_ops
{
	null_op,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	sa,
	sb,
	ss
};

/*FUNCTION PROTOTYPES*/

/*DATA FUNCTIONS*/
void		parse_data(t_data *data, int argc, char **argv, bool reporting);
//void		create_stack(t_data *data, t_stack stack, int size);
bool		check_sorted(t_data *data);
void		free_all(t_data *data);
void		put_error(t_data *data);

/*STACK FUNCTIONS*/
void		fill_stack(t_data *data, t_stack *stack, int argc, char **argv);
void		check_argv_validity(char *argv);
void		check_duplicate(t_stack *stack);
void		assign_rank(int *arr, int *rank, int size);

int			get_upper(t_stack *stack, int index);
int			get_lower(t_stack *stack, int index);
int			peek_value(t_stack *stack, int index);
int			check_size(t_stack *stack);
bool		is_empty(t_stack *stack);

/* OPERATION UTILS*/
void		record_instruction(t_data *data, enum e_ops instruction);
void		report_instructions(t_list *head);
const char	*verbalize_instruction(enum e_ops instruction);
enum e_ops	map_instructions(t_list *instruction_list);

/* STACK OPERATIONS */
void		push(t_stack *stack_from, t_stack *stack_to);
void		push_a(t_data *data);
void		push_b(t_data *data);
void		rotate(t_stack *stack);
void		rotate_a(t_data *data);
void		rotate_b(t_data *data);
void		rotate_ab(t_data *data);
void		reverse_rotate(t_stack *stack);
void		reverse_rotate_a(t_data *data);
void		reverse_rotate_b(t_data *data);
void		reverse_rotate_ab(t_data *data);
void		swap(t_stack *stack);
void		swap_a(t_data *data);
void		swap_b(t_data *data);
void		swap_ab(t_data *data);

#endif
