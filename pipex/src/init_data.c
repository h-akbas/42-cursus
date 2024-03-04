/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:53:24 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:41:28 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <stdlib.h>

static char	**init_env_paths(char **env, t_data *d);
static char	***parse_cmd_list(char **argv, int n_cmd, t_data *d);

void	init_data(t_data *d, int argc, char **argv, char **env)
{
	errno = 0;
	d->allocated_pointers = NULL;
	d->env = env;
	d->env_paths = init_env_paths(env, d);
	d->here_doc = false;
	d->limiter = NULL;
	d->input_file = argv[1];
	d->output_file = argv[argc - 1];
	d->n_cmd = argc - 3 - d->here_doc;
	d->commands = parse_cmd_list(argv + 2 + d->here_doc, d->n_cmd, d);
	d->last_cmd_exit_status = EXIT_SUCCESS;
}

static char	**init_env_paths(char **env, t_data *d)
{
	char	**paths;
	char	*path;
	int		i;

	paths = NULL;
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		path = s_alloc(ft_strdup("/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:\
		/usr/local/sbin:/opt/bin:/opt/sbin"), TRACK, d);
	else
		path = env[i] + 5;
	paths = ft_split(path, ':');
	if (!paths)
		put_error("ft_split", "fail to split env path", EXIT_FAILURE, d);
	track_alloc(d, paths);
	i = 0;
	while (paths[i])
		track_alloc(d, paths[i++]);
	return (paths);
}

static char	***parse_cmd_list(char **argv, int n_cmd, t_data *d)
{
	char	***cmd_list;
	int		i;

	i = 0;
	cmd_list = s_alloc(ft_calloc((n_cmd + 1), sizeof(char **)), TRACK, d);
	while (i < n_cmd)
	{
		cmd_list[i] = parse_cmd(argv[i], d);
		if (cmd_list[i][0] == NULL)
			put_error("parse put_error", "empty argument", EXIT_FAILURE, d);
		i++;
	}
	cmd_list[i] = NULL;
	return (cmd_list);
}
