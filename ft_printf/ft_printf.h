/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <halilakbas1992@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:17:27 by hakbas            #+#    #+#             */
/*   Updated: 2023/12/14 21:08:00 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_putnbr(int n);
int	ft_putchar(char chr);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_puthexa(unsigned int nbr, const char format);
int	ft_printunbr(unsigned int nbr);
int	ft_printf(const char *str, ...);

#endif 