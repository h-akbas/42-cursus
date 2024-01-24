/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:36:23 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/11 20:09:12 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
char	*fetch_line(char *line, char *buffer, int *end, int fd);
char	*make_line(char *buffer, int *end);
size_t	get_end(char *line);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strjoin_gnl(char *s1, char *s2, int *end);
void	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);

#endif
