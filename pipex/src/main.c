/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:54:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 20:49:11 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>

static void	check_args(int argc, char **argv);

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	check_args(argc, argv);
	init_data(&data, argc, argv, env);
	execute_pipeline(&data);
	ft_lstclear(&data.allocated_pointers, free);
	return (data.last_cmd_exit_status);
}

static void	check_args(int argc, char **argv)
{
	(void)argv;
	if (argc != 5)
		put_error("parse error", "wrong number of arguments",
			EXIT_FAILURE, NULL);
}
