/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:01:48 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 15:01:40 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s, const char *set)
{
	const char	*end;
	size_t		tlen;
	char		*str;

	if (!s || !set)
		return (NULL);
	while (*s && is_in_set(*s, set))
		s++;
	end = s + ft_strlen(s) - 1;
	while (end > s && is_in_set(*end, set))
		end--;
	tlen = end - s + 1;
	str = (char *)malloc(tlen + 1);
	if (str)
	{
		ft_strlcpy(str, s, tlen + 1);
		str[tlen] = '\0';
	}
	return (str);
}
