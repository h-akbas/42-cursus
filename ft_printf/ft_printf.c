/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:17:22 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/14 19:27:21 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	check_formatter(va_list list, char formatter, int count)
{
	if (formatter == 'c')
		count += ft_putchar(va_arg(list, int));
	if (formatter == 's')
		count += ft_putstr(va_arg(list, char *));
	if (formatter == 'p')
		count += ft_putptr(va_arg(list, void *));
	if (formatter == 'd' || formatter == 'i')
		count += ft_putnbr(va_arg(list, int));
	if (formatter == 'u')
		count += ft_printunbr(va_arg(list, unsigned int));
	if (formatter == 'x')
		count += ft_puthexa(va_arg(list, unsigned int), 'x');
	if (formatter == 'X')
		count += ft_puthexa(va_arg(list, unsigned int), 'X');
	if (formatter == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	list;

	i = 0;
	count = 0;
	va_start(list, format);
	while (format[i])
	{
		if (write(1, "", 0) < 0)
			return (-1);
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				break ;
			count = check_formatter(list, format[i + 1], count);
			i++;
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}
