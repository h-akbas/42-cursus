/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:26:30 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:35:08 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "obj.h"

void	check_args(int argc, char **argv);
void	put_error(t_data *data, char *desc);
void	track_allocation(t_data *d, void *pointer);
void	free_data(t_data *data);
void	init_data(t_data *data, char *map_path);
void	stop_game(t_data *param);


#endif
