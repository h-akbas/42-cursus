/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:55:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 05:13:34 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arg.h"
#include <stdlib.h>

void free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
bool	is_valid_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!has_only_num(args[i]))
			return (false);
		if (has_repetion(tmp, args, i))
			return (false);
		if (tmp < MIN_INT || tmp > MAX_INT)
			return (false);
		i++;
	}
	if (argc == 2)
		free_args(args);
	return (true);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

bool	has_only_num(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
bool has_repetion(int nbr, char **argv, int start_index)
{
	start_index++;
	while (argv[start_index])
	{
		if (ft_atoi(argv[start_index]) == nbr)
			return (true);
		start_index++;
	}
	return (false);
}
