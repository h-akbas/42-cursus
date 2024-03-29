/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: halilakbas <halilakbas@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:06:57 by hakbas            #+#    #+#             */
/*   Updated: 2023/10/12 18:59:13 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
