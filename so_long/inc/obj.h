/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:26:04 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/13 00:43:21 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_H
# define OBJ_H

# include <stdint.h>
# include "../libs/libft/libft.h"

# define WIN_HEIGHT 1080
# define WIN_WIDTH 1920
# define BLOCK_NUMBER 7
# define FRAME_NUMBER 12

typedef struct s_pos
{
	int32_t			x;
	int32_t			y;
}					t_pos;

typedef struct s_size
{
	int32_t			width;
	int32_t			height;
}					t_size;

typedef enum e_exit_status
{
	CLOSED,
	OPEN
}					t_exit_status;

typedef enum e_direction
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}					t_direction;

typedef struct s_frame_to_display
{
	void			*frame;
	t_pos
			place_to_display;
}					t_frame_to_display;

typedef enum e_block
{
	NULL_BLOCK,
	EMPTY,
	WALL,
	COLLECTIBLE,
	EXIT,
	PLAYER
}					t_block;

typedef enum states
{
	PLAYING,
	END_GAME,
	END_SCREEN
}					t_states;

typedef struct s_map
{
	t_block			**grid;
	int32_t			width;
	int32_t			height;
}					t_map;

typedef struct s_data
{
	t_list			*allocated_pointers;
	t_states		state;
	void			*mlx;
	t_size			window;
	int32_t			block_size;
	void			*img_set[BLOCK_NUMBER][4];
	void			*frames_set[4][FRAME_NUMBER];
	t_list			*frames_queue;
	float			next_frame_time;
	void			*move_count_img;
	int				move_count;
	t_map			*map;
	t_pos
			player;
	t_direction		player_orientation;
	t_pos
			exit;
	t_exit_status	exit_status;
	int				collectible_count;
}					t_data;

#endif
