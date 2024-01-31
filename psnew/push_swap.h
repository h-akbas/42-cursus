/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:11:55 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 08:26:31 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include <stdbool.h>
# include "arg.h"
# include "stack.h"
# include "sort.h"
# include "ops.h"

# define INVALID_ERROR 1
# define MEMORY_ERROR 2
# define STACK_A 0
# define STACK_B 1

void	print_error(int status);
void	free_args(char **args);

void	free_stack(t_stack *stack);
void	free_table(t_table *table);
void	print_error(int status);

#endif
