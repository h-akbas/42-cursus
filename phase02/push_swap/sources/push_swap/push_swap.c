/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:33:25 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 18:58:16 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_args(char **args);

int	main(int argc, char **argv)
{
	t_data	data;
	char	**args;
	int		argc_new;

	if (argc <= 1)
		return (-42);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc_new = ft_count_args(args);
		if (args != NULL && *args != NULL)
		{
			parse_data(&data, argc_new, args, true);
			free(args);
		}
	}
	else
		parse_data(&data, argc, argv, true);
	sort(&data);
	report_instructions(data.instructions);
	free_all(&data);
	exit(EXIT_SUCCESS);
}

static int	ft_count_args(char **args)
{
	int	count;

	count = 0;
	while (*args)
	{
		count++;
		args++;
	}
	return (count + 1);
}
