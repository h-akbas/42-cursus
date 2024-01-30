/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 05:00:37 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 08:24:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "stack.h"

void	sort_all(t_table *table);
void 	process_stack_a(t_table *table, int rotation_hold, int key_number,
															int partition_size);
void	rotate_or_push_b(t_table *table, int rotation_hold, int key_number,
															int partition_size);
void best_rr(t_table *box, int pos, int side);

#endif
