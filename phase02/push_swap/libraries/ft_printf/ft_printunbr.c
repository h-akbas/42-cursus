/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:17:31 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/14 19:22:35 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunbr(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr > 9)
	{
		i += ft_printunbr(nbr / 10);
		i += ft_printunbr(nbr % 10);
	}
	if (nbr <= 9)
	{
		nbr += 48;
		i += write(1, &nbr, 1);
	}
	return (i);
}
