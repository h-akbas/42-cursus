## STUDY NOTES:

# MiniLibx (MLX) key functions
```c
#include  <mlx.h>

/*
*	Initialises the MLX library. Must be called before using any other functions.
*
*/
void		*mlx_init();

/*
*	Creates a new windows on the screen
*	in size_x * size_y dimension
*	named title (in the window's title bar)
*	mlx_ptr: connection identifier returned by mlx_init()
*	return NULL on failure or void * window identifier
*
*	NOTE: It's possible to create more than one windows using MLX.
*
*/
void		*mlx_new_window ( void *mlx_ptr, int size_x, int size_y, char *title );

/*
*	clears the windows (or paint in black)
*	mlx_ptr: connection identifier
*	win_ptr: window identifier
*	returns nothing meaningful
*/
int		mlx_clear_window ( void *mlx_ptr, void *win_ptr );

/*
*
*	destroys (frees) the windows
*	mlx_ptr: connection identifier
*	win_ptr: window identifier
*	returns nothing meaningful
*/
int		mlx_destroy_window ( void *mlx_ptr, void *win_ptr );


* mlx_hook: Registers events.
* mlx_loop: Loops over the MLX pointer, triggering each hook in order of registration.
* mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.
* mlx_put_image_to_window: Puts your image to the screen at the given coordinates.
* mlx_destroy_image: Frees the image.
* mlx_destroy_window: Frees the window instance.
* mlx_destroy_display: Frees MLX.

