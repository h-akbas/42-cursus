/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:29:11 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/17 12:04:16 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"
#include "./libft/libft.h"
#include "push_swap.h"

static void		assert_digit(char c);
static int		extract_ints(const char *str);
static t_stack	*parse_args(char **argv);
static void		destroy_args(char **args);

t_stack	*parse_data(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc == 2)
		a = parse_args(argv);
	else
	{
		while (i < argc)
		{
			j = extract_ints(argv[i]);
			append_stack(&a, create_new_stack(j));
			i++;
		}
	}
	return (a);
}

static void	assert_digit(char c)
{
	if (!ft_isdigit(c))
		put_error();
	else
		return ;
}

static int	extract_ints(const char *str)
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
	assert_digit(*str);
	while (*str)
	{
		assert_digit(*str);
		result = result * 10 + (*str - 48);
		str++;
	}
	if ((sign * result) > 2147483647 || (sign * result) < -2147483648)
		put_error();
	return (sign * result);
}

static t_stack	*parse_args(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], ' ');
	assert_not_null(tmp);
	while (tmp[i])
	{
		j = extract_ints(tmp[i]);
		append_stack(&a, create_new_stack(j));
		i++;
	}
	destroy_args(tmp);
	free(tmp);
	return (a);
}

static void	destroy_args(char **args)
{
	char	*tmp;

	if (!args)
		return ;
	while (*args)
	{
		tmp = *args;
		args++;
		free(tmp);
	}
}
