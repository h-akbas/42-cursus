/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:57:38 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/30 04:37:37 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		**free_all(char **result, int j);
static int		count_words(char const *s, char c);
static size_t	ft_strlcpy(char *dst, const char *src, size_t size);
static char		**fill_result(char **res, char const *s, char c, int wc);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		wc;

	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	wc = count_words(s, c);
	return (fill_result(result, s, c, wc));
}

static char	**free_all(char **result, int j)
{
	while (j >= 0)
	{
		free(result[j]);
		j--;
	}
	free(result);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int		count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
		{
			in_word = 0;
		}
		s++;
	}
	return (count);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	char 	*tmp;

	src_len = 0;
	tmp = (char *)src;
	while (tmp[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

static char	**fill_result(char **res, char const *s, char c, int wc)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (wc--)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = (char *)malloc(i - start + 1);
		if (!res[j])
			return (free_all(res, j - 1));
		ft_strlcpy(res[j++], s + start, i - start + 1);
	}
	res[j] = 0;
	return (res);
}
