/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:18:18 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/14 19:33:41 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa(unsigned long long nbr)
{
	int		i;
	char	c;

	i = 0;
	if (nbr >= 16)
	{
		i += ft_hexa(nbr / 16);
		i += ft_hexa(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			c = nbr + 48;
		else if (nbr >= 10 && nbr <= 16)
			c = nbr + 'a' - 10;
		i += write(1, &c, 1);
	}
	return (i);
}

int	ft_putptr(void *ptr)
{
	unsigned long long	p;

	p = (unsigned long long)ptr;
	write(1, "0x", 2);
	return (ft_hexa(p) + 2);
}
