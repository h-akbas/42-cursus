/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:53:24 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/05 21:18:41 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <stdlib.h>

static char	**init_env_paths(char **env, t_data *data);
static char	***parse_cmd_list(char **argv, int n_cmd, t_data *data);

void	init_data(t_data *data, int argc, char **argv, char **env)
{
	errno = 0;
	data->allocated_pointers = NULL;
	data->env = env;
	data->env_paths = init_env_paths(env, data);
	data->here_doc = false;
	data->limiter = NULL;
	data->input_file = argv[1];
	data->output_file = argv[argc - 1];
	data->n_cmd = argc - 3 - data->here_doc;
	data->commands = parse_cmd_list(argv + 2 + data->here_doc,
			data->n_cmd, data);
	data->last_cmd_exit_status = EXIT_SUCCESS;
}

static char	**init_env_paths(char **env, t_data *data)
{
	char	**paths;
	char	*path;
	int		i;

	paths = NULL;
	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		path = safe_alloc(ft_strdup("/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:\
		/usr/local/sbin:/opt/bin:/opt/sbin"), TRACK, data);
	else
		path = env[i] + 5;
	paths = ft_split(path, ':');
	if (!paths)
	{
		put_error("ft_split", "fail to split env path", EXIT_FAILURE, data);
		return (NULL);
	}
	else
		track_alloc(data, paths);
	i = 0;
	while (paths[i])
		track_alloc(data, paths[i++]);
	return (paths);
}

static char	***parse_cmd_list(char **argv, int n_cmd, t_data *data)
{
	char	***cmd_list;
	int		i;

	i = 0;
	cmd_list = safe_alloc(ft_calloc((n_cmd + 1), sizeof(char **)), TRACK, data);
	while (i < n_cmd)
	{
		cmd_list[i] = parse_cmd(argv[i], data);
		if (cmd_list[i][0] == NULL)
			put_error("parse put_error", "empty argument", EXIT_FAILURE, data);
		i++;
	}
	cmd_list[i] = NULL;
	return (cmd_list);
}
