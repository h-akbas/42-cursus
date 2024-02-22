/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:41:12 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/19 00:27:30 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include <stdbool.h>

void	put_error(void);
void	put_error_free(t_stack **a, char **args, bool is_argc_2);
void	assert_not_null(void *ptr);

#endif
