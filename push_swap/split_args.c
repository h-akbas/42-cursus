/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 23:41:09 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/19 00:03:00 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <stdlib.h>

static int	count_words(char *str, char separator)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*str)
	{
		inside_word = false;
		while (*str == separator && *str)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	assert_not_null(next_str);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**split_args(char *str, char separator)
{
	int		wc;
	char	**result;
	int		i;

	i = 0;
	wc = count_words(str, separator);
	if (!wc)
		put_error();
	result = malloc(sizeof(char *) * (size_t)(wc + 2));
	assert_not_null(result);
	while (wc-- >= 0)
	{
		if (i == 0)
		{
			result[i] = malloc(sizeof(char));
			assert_not_null(result[i]);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(str, separator);
	}
	result[i] = NULL;
	return (result);
}
