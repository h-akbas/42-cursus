/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halilakbas <halilakbas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 20:55:38 by ugerkens          #+#    #+#             */
/*   Updated: 2024/01/06 21:14:08 by halilakbas       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "stack.h"

// MAIN CHECKER
int			main(int argc, char *argv[]);
void		read_op(t_table *data);
bool		test_sort(t_table *data);

// CHECK SORT
void		error_read_op(t_table *data, char *line);
int			get_next_line_ps(int fd, char *line);
enum e_op	string_to_op(const char *str);
void		call_op(t_table *data, enum e_op op);

#endif