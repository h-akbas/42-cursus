/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:50:02 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/15 00:09:55 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stddef.h>
# include <stdbool.h>

# define HEIGHT 64
# define WIDTH 64
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit;
	void	*collect;
	char	**map;
	int		win_width;
	int		win_height;
	int		map_width;
	int		map_height;
	int		pl_x;
	int		pl_y;
	bool	is_player_init;
	size_t	player_moves;
	int		coll;
	int		coll_chk;
	bool	is_error;
	int		fd;
}			t_data;

typedef struct s_chk
{
	int		i;
	int		j;
	int		p_count;
	int		e_count;
	int		c_count;
	int		w_count;
}			t_chk;
//Program-wide used functions
void    ft_assert(bool condition, char *message, t_data *data);
void	init_game(char *map, t_data *data);

//map_utils.c
void	get_height(char *str, t_data *data);
char	**parse_map(t_data *data, char *str);

//map_checking
int check_map(t_data *data);
bool	is_valid_char(char c);
void	find_path(t_data *data, int x, int y);
void	get_player_loc(t_data *data);

#endif