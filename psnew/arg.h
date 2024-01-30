/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 04:55:42 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 08:25:45 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARG_H
# define ARG_H

# include <stdbool.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

bool	is_valid_args(int argc, char **argv);
int		ft_atoi(const char *str);
bool	has_only_num(char *str);
bool 	has_repetion(int nbr, char **argv, int start_index);
char	**ft_split(char const *s, char c);
#endif
