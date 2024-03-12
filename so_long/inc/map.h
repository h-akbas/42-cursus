/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 00:07:05 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:46:52 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "obj.h"

void	init_map(t_data *data, char *map_path);
void	cut_nl(char *line);
void	reading_error(t_data *d, char *description, int fd);
void	line_to_grid(t_block **grid, char *line, int raw);
void	import_map(t_data *data, char *map_path);
int		count_block(t_map *map, t_block block_type);
t_pos	get_position(t_map *map, t_block block_type);
void	check_valid_path(t_data *data, t_map *map);

#endif
