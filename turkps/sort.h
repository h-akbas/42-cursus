/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:16:30 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/02 01:12:09 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SORT_H
# define SORT_H

# include "stack.h"
# include "operation.h"

void		sort(t_stack **stack_a);
void		sort_three(t_stack **stack_a);
 int		check_rarb_a(t_stack *a, t_stack *b, int c);
int			check_rrarrb_a(t_stack *a, t_stack *b, int c);
int			check_rarrb_a(t_stack *a, t_stack *b, int c);
int			check_rrarb_a(t_stack *a, t_stack *b, int c);
int			check_rarb(t_stack *a, t_stack *b, int c);
int			check_rrarrb(t_stack *a, t_stack *b, int c);
int			check_rrarb(t_stack *a, t_stack *b, int c);
int			check_rarrb(t_stack *a, t_stack *b, int c);
int			check_rarb_a(t_stack *a, t_stack *b, int c);
int			check_rrarrb_a(t_stack *a, t_stack *b, int c);
int			check_rarrb_a(t_stack *a, t_stack *b, int c);
int			check_rrarb_a(t_stack *a, t_stack *b, int c);
int			get_ab_rotation(t_stack *a, t_stack *b);
int			get_ba_rotation(t_stack *a, t_stack *b);
int			do_rarb(t_stack **a, t_stack **b, int c, char s);
int			do_rrarrb(t_stack **a, t_stack **b, int c, char s);
int			do_rrarb(t_stack **a, t_stack **b, int c, char s);
int			do_rarrb(t_stack **a, t_stack **b, int c, char s);

#endif
