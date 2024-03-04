/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_bin_path_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 23:49:49 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 21:43:29 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

static char	*check_bin_with_path(char *bin, t_data *d);
static char	*find_path(char *bin, char **env_path, t_data *d);
static char	*join_path(char *dir, char *file, t_data *d);
static bool	check_access(char *bin, t_data *d);

char	*get_bin_path(char *bin, char **env_path, t_data *d)
{
	if (ft_strchr(bin, '/'))
		return (check_bin_with_path(bin, d));
	return (find_path(bin, env_path, d));
}

static char	*check_bin_with_path(char *bin, t_data *d)
{
	if (check_access(bin, d))
		return (bin);
	if (errno == EACCES)
		put_error("permission denied", bin, 126, d);
	else if (errno != ENOENT)
		put_error("command not found", bin, 127, d);
	return (NULL);
}

static char	*find_path(char *bin, char **env_path, t_data *d)
{
	int		i;
	bool	permission_denied;
	char	*full_path;

	i = 0;
	permission_denied = false;
	if (!env_path)
		put_error("command not found", bin, 127, d);
	while (env_path[i])
	{
		full_path = join_path(env_path[i], bin, d);
		if (check_access(full_path, d))
			return (full_path);
		if (errno == EACCES)
			permission_denied = true;
		free(full_path);
		i++;
	}
	if (permission_denied)
		put_error("permission denied", bin, 126, d);
	else
		put_error("command not found", bin, 127, d);
	return (NULL);
}

static char	*join_path(char *dir, char *file, t_data *d)
{
	char	*slash_path;
	char	*full_path;

	slash_path = ft_strjoin(dir, "/");
	if (!slash_path)
		put_error("ft_strjoin", "fail to join file path", EXIT_FAILURE, d);
	full_path = ft_strjoin(slash_path, file);
	if (!full_path)
		put_error("ft_strjoin", "fail to join file path", EXIT_FAILURE, d);
	free(slash_path);
	return (full_path);
}

static bool	check_access(char *bin, t_data *d)
{
	if (access(bin, X_OK) == EXIT_SUCCESS)
		return (true);
	if (errno != 0 && errno != EACCES && errno != ENOENT)
		put_sys_error(bin, errno, d);
	return (false);
}
