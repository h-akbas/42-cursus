/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:32:01 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/11 10:54:59 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "stack.h"
# include <unistd.h>

void		sa(t_stack **a, int j);
void		sb(t_stack **b, int j);
void		ss(t_stack **a, t_stack **b, int j);
void		pa(t_stack **a, t_stack **b, int j);
void		pb(t_stack **a, t_stack **b, int j);
void		ra(t_stack **a, int j);
void		rb(t_stack **b, int j);
void		rr(t_stack **a, t_stack **b, int j);
void		rra(t_stack **a, int j);
void		rrb(t_stack **b, int j);
void		rrr(t_stack **a, t_stack **b, int j);

#endif
