/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:54:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:43:55 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <stdlib.h>

static void	check_args(int argc, char **argv);

int	main(int argc, char **argv, char **env)
{
	t_data	d;

	check_args(argc, argv);
	init_data(&d, argc, argv, env);
	execute_pipeline(&d);
	ft_lstclear(&d.allocated_pointers, free);
	return (d.last_cmd_exit_status);
}

static void	check_args(int argc, char **argv)
{
	if (argc < 5 || (ft_strcmp(argv[1], "here_doc") == 0 && argc < 6))
		put_error("parse error", "not enough arguments", EXIT_FAILURE, NULL);
}
