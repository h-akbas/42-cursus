/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:18:06 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/14 19:18:10 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	unsigned int	nbr;
	int				i;

	nbr = n;
	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		nbr = n * (-1);
	}
	if (nbr > 9)
	{
		i += ft_putnbr(nbr / 10);
		i += ft_putnbr(nbr % 10);
	}
	if (nbr <= 9)
	{
		nbr += 48;
		i += write(1, &nbr, 1);
	}
	return (i);
}
