/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 19:14:11 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:50:58 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		left;
	size_t	dst_len;

	i = 0;
	dst_len = ft_strlen(dst);
	left = dstsize - dst_len - 1;
	if (dstsize < dst_len)
		return (dstsize + ft_strlen(src));
	while (src[i] && left > 0)
	{
		dst[dst_len + i] = src[i];
		left--;
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

int	is_hexa(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 87);
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= '0' && c <= '9')
		return (c - 48);
	else
		return (0);
}

int	ft_atoi_hex(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] == '0' || str[i] == 'x')
		i++;
	while (str[i])
	{
		res *= 16;
		res += is_hexa(str[i]);
		i++;
	}
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0') && n > 0)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
		n--;
	}
	return (0);
}
