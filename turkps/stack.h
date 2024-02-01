/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:39:48 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/01 21:49:45 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;
void		append_stack(t_stack **stack, t_stack *stack_new);
t_stack		*create_new_stack(int content);
int			check_duplication(t_stack *a);
void		destroy_stack(t_stack **lst);
t_stack		*get_last_item(t_stack *lst);
int			get_stack_size(t_stack *stack);
int			get_min(t_stack *stack);
int			get_max(t_stack *stack);
int			get_index(t_stack *stack, int nbr);
void		sort(t_stack **stack_a);
int			check_sort(t_stack *stack_a);
t_stack		*parse_data(int argc, char **argv);
int			check_access_a(t_stack *stack_a, int nbr_push);
int			check_access_b(t_stack *stack_b, int nbr_push);




#endif
