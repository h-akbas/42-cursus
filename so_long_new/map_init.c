/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 17:06:01 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 18:36:20 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

void	init_map(t_data *d, char *map_path)
{
	d->map = malloc(sizeof(t_map));
	track_allocation(d, d->map);
	d->map->grid = NULL;
	d->map->x = 0;
	d->map->y = 0;
	import_map(d, map_path);
	check_map_validity(d, d->map);
}