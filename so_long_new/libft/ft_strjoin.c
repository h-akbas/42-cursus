/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:56:46 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 15:01:40 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	total;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total = len1 + len2;
	str = (char *)malloc(sizeof(char) * total + 1);
	if (str)
	{
		ft_strlcpy(str, s1, len1 + 1);
		ft_strlcat(str + len1, s2, total + 1);
	}
	return (str);
}
