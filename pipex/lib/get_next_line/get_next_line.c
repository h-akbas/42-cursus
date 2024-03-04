/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:29:50 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 00:03:25 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char	*make_line(char *buffer, int *end)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, i);
	line[i] = '\0';
	if (i > 0 && line[i - 1] == '\n')
		*end = i - 1;
	return (line);
}

size_t	get_end(char *line)
{
	ssize_t	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (line[i] == '\n' || line[i] == '\0')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*fetch_line(char *line, char *buffer, int *end, int fd)
{
	char	temp[BUFFER_SIZE + 1];
	ssize_t	read_stat;
	size_t	line_len;

	while (*end == -1)
	{
		ft_bzero(temp, BUFFER_SIZE + 1);
		read_stat = read(fd, temp, BUFFER_SIZE);
		if (read_stat == -1)
		{
			free (line);
			ft_bzero(buffer, BUFFER_SIZE + 1);
			return (NULL);
		}
		line_len = get_end(temp);
		ft_strlcpy_gnl(buffer, &temp[line_len], BUFFER_SIZE + 1);
		temp[line_len] = '\0';
		line = ft_strjoin_gnl(line, temp, end);
		if (read_stat == 0)
		{
			ft_bzero(buffer, BUFFER_SIZE + 1);
			break ;
		}
	}
	return (line);
}

int	get_next_line(int fd, char **return_line)
{
	static char	stash[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			eol_loc;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (EXIT_FAILURE);
	eol_loc = -1;
	line = make_line(stash[fd], &eol_loc);
	if (!line)
		return (EXIT_FAILURE);
	ft_strlcpy_gnl(stash[fd], &stash[fd][eol_loc + 1], BUFFER_SIZE + 1);
	line = fetch_line(line, stash[fd], &eol_loc, fd);
	if (!line)
	{
		free(line);
		return (EXIT_FAILURE);
	}
	*return_line = line;
	return (EXIT_SUCCESS);
}
