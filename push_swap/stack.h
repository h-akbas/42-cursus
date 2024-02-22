/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:39:48 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/22 15:26:50 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

char		**split_args(char *str, char separator);
void		append_stack(t_stack **stack, int num);
t_stack		*create_new_stack(int content);
void		destroy_args(char **args);
void		destroy_stack(t_stack **lst);
t_stack		*get_last_item(t_stack *lst);
int			get_stack_size(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_index(t_stack *stack, int nbr);
void		sort(t_stack **stack_a);
int			check_sort(t_stack *stack_a);
void		init_data(t_stack **a, char **argv, bool is_argc_2);
int			check_access_a(t_stack *stack_a, int nbr_push);
int			check_access_b(t_stack *stack_b, int nbr_push);

#endif
