/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:18:01 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/14 19:30:13 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nbr, const char format)
{
	int		i;
	char	c;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_puthexa(nbr / 16, format);
		i += ft_puthexa(nbr % 16, format);
	}
	else
	{
		if (nbr <= 9)
			c = nbr + 48;
		else if (nbr >= 10 && nbr <= 15)
		{
			if (format == 'X')
				c = nbr + 'A' - 10;
			if (format == 'x')
				c = nbr + 'a' - 10;
		}
		i += write(1, &c, 1);
	}
	return (i);
}
