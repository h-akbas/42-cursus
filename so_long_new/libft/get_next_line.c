/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:29:50 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/14 23:03:45 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	end = -1;
	line = make_line(buffer, &end);
	if (!line)
		return (NULL);
	ft_strlcpy_gnl(buffer, &buffer[end + 1], BUFFER_SIZE + 1);
	line = fetch_line(line, buffer, &end, fd);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
