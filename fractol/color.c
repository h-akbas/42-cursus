/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:00:43 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/17 23:57:28 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

char	*fill_color(char *r, char *g, char *b)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 10);
	if (str == NULL)
		return (NULL);
	str[i++] = '0';
	str[i++] = 'x';
	str[i] = '\0';
	ft_strlcat(str, r, 10);
	ft_strlcat(str, g, 10);
	ft_strlcat(str, b, 10);
	return (str);
}

char	*dec_to_hex(unsigned int num)
{
	char	*tmp;
	int		mod;
	int		i;

	i = 1;
	mod = 0;
	tmp = malloc(sizeof(char) * 4);
	if (tmp == NULL)
		return (NULL);
	while (num != 0)
	{
		mod = num % 16;
		if (mod < 10)
			tmp[i--] = mod + 48;
		else
			tmp[i--] = mod + 55;
		num /= 16;
	}
	tmp[2] = '\0';
	return (tmp);
}

int	convert_colors(int red, int green, int blue)
{
	char	*r;
	char	*g;
	char	*b;
	char	*color;
	int		res;

	r = dec_to_hex(red);
	g = dec_to_hex(green);
	b = dec_to_hex(blue);
	color = fill_color(r, g, b);
	free(r);
	free(g);
	free(b);
	res = ft_atoi_hex(color);
	free(color);
	return (res);
}

int	color_pixel(t_data *d)
{
	double	n;
	int		res;

	if (d->iter == d->max_iter && d->fractal != 2)
		return (0x000000);
	n = (double)d->iter / (double)d->max_iter;
	d->color->r = d->color->r_start * (1 - n) + d->color->r_end * n;
	d->color->g = d->color->g_start * (1 - n) + d->color->g_end * n;
	d->color->b = d->color->b_start * (1 - n) + d->color->b_end * n;
	res = convert_colors(d->color->r, d->color->g, d->color->b);
	return (res);
}
