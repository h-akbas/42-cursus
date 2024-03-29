/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:06:57 by hakbas            #+#    #+#             */
/*   Updated: 2024/02/14 20:54:42 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

size_t	ft_strlen(const char *s)
{
	char	*start;

	start = (char *)s;
	while (*s)
	{
		s++;
	}
	return (s - start);
}
