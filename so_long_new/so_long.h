/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:50:02 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 18:58:07 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include <stddef.h>
# include <stdbool.h>

# define HEIGHT 64
# define WIDTH 64
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define IMG_MAX 6
# define BLOCK_NUMBER 7

typedef enum e_block
{
	NULL_BLOCK,
	WALL,
	FLOOR,
	COLLECTIBLE,
	PLAYER,
	EXIT,
}			t_block;

typedef struct s_pos
{
	size_t	x;
	size_t	y;
}			t_pos;

typedef struct s_map
{
	t_block **grid;
	size_t	x;
	size_t	y;
}			t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img[IMG_MAX];
	t_map	*map;
	int		win_width;
	int		win_height;
	t_pos	pos;
	bool	is_player_init;
	size_t	player_moves;
	int		coll;
	int		coll_chk;
	bool	is_error;
	int		fd;
	t_list	*allocated_pointers;
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
/*
**	If condition false, write message to stderr, destroy data
**	else return;
*/
void	ft_assert(bool condition, char *message, t_data *data);

/*
**		Check map data,
**		Parse map to t_data data
**		Create mlx connection
**		Create mlx windows
**		Create image frames
**		Render images
**		mlx_key_hook: assign keyboard controls / keys: //TODO
**		mlx_hook:	// TODO
**		mlx_loop: keep running the games until exit from key,
**					kill from signal or crash
*/
void	init_game(char *map, t_data *data);

/*
**		cat map | wc -l
*/
void	get_height(char *str, t_data *data);

/*
**		get_next_line(fd of map file)
**		return pointer to string to map lines if successful
**		or exits the program due to open/close or malloc errors
*/
char	**parse_map(t_data *data, char *str);

/*
**		create map_checker struct
**		do element, wall and path checks on map_checker str
**		return 1 if all checks are successful
**		exits program if any of checks failed or due to malloc error
*/
int		check_map(t_data *data);

/*
**		Runs character checks on raw map data.
**		return true if char c is
**								'0': (floor),
**								'1': (wall),
**								'C': (collectible),
**								'E': (map_exit),
**								'P': (player)
**		return false if c is any character else
*/
bool	is_valid_char(char c);

/*
**		checks player's movement around the map
**		prevents movement into walls
**		increments collected collectible count
**						when movement into collectible cell
**		handles movement into exit cell
**		recursive call on neighbouring cells 
*/
void	check_map_movements(t_data *data, int x, int y);

/*
**		keep track of player's position
**		assign collectible count
*/
void	get_map_elements(t_data *data);

/*
**		free heap allocated memory
**		exits failure
*/
void	clean_exit(t_data *data);

/*
**	Create images of elements from xpm files
**	Exits the program if mlx call fails 
*/
void	create_images(t_data *data, int width, int height);

/*
**
**
**
*/
void	render(t_data *data);

/*
**
**
**
*/
int	key_hook(int key_code, t_data *d);


/*
**
**
*/
void	track_allocation(t_data *d, void *pointer);

/*
**
**
*/
void	import_map(t_data *d, char *map_path);

/*
**
**
*/
void	cut_nl(char *line);

/*
**
**
*/
void	read_error(t_data *d, char *description, int fd);

/*
**
**
*/
void	line_to_grid(t_block **grid, char *line, int raw);


/*
**
**
**
*/
int	count_block(t_map *map, t_block block_type);

/*
**
**
*/
t_pos	get_position(t_map *map, t_block block_type);


/*
**
**
*/
void	check_map_validity(t_data *d, t_map *map);

/*
**
**
*/
void	check_valid_path(t_data *d, t_map *map);

/*
**
*/
void	init_map(t_data *d, char *map_path);
#endif