/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:57:43 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 08:26:55 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "stack.h"

typedef enum
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
} e_op;

void 	print_op(e_op op);
void	sa(t_table *table, bool print);
void	sb(t_table *table, bool print);
void	ss(t_table *table, bool print);
void	pa(t_table *table, bool print);
void	pb(t_table *table, bool print);
void	ra(t_table *table, bool print);
void	rb(t_table *table, bool print);
void	rr(t_table *table, bool print);
void	rra(t_table *table, bool print);
void	rrb(t_table *table, bool print);
void	rrr(t_table *table, bool print);

#endif
