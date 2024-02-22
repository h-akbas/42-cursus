/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:29:11 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/19 00:27:00 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"
#include "./libft/libft.h"
#include "push_swap.h"

static long		extract_nums(const char *str);
static bool		check_duplication(t_stack *a, long num);

void	init_data(t_stack **a, char **argv, bool is_argc_2)
{
	int		i;
	long	num;

	i = 0;
	while (argv[i])
	{
		if (invalid_input(argv[i]))
			put_error_free(a, argv, is_argc_2);
		num = extract_nums(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			put_error_free(a, argv, is_argc_2);
		if (check_duplication(*a, (int)num))
			put_error_free(a, argv, is_argc_2);
		append_stack(a, (int)num);
		++i;
	}
	if (is_argc_2)
		destroy_args(argv);
}

static long	extract_nums(const char *str)
{
	int		sign;
	long	result;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (sign * result);
}

static bool	check_duplication(t_stack *a, long num)
{
	if (!a)
		return (false);
	while (a)
	{
		if (a->nbr == num)
			return (true);
		a = a->next;
	}
	return (false);
}
