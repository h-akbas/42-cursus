/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:29:11 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/01 20:50:03 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"


static int	extract_ints(const char *str);
static t_stack	*parse_args(char **argv);

t_stack	*parse_data(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	i = 1;
	a = NULL;
	if (argc < 2)
		put_error();
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
static int	extract_ints(const char *str)
{
	int				sign;
	long long int	i;

	i = 0;
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
		if (!ft_isdigit(*str))
			put_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		put_error();
	return (sign * i);
}

static t_stack	*parse_args(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	a = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
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
