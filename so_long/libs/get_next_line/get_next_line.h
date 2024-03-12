/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:36:23 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/03 00:03:06 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# include <stdlib.h>
# include "../libft/libft.h"

int		get_next_line(int fd, char **return_line);
char	*fetch_line(char *line, char *buffer, int *end, int fd);
char	*make_line(char *buffer, int *end);
size_t	get_end(char *line);
char	*ft_strjoin_gnl(char *s1, char *s2, int *end);
void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);

#endif
