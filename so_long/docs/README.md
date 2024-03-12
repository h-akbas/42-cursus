## STUDY NOTES:

# MiniLibx (MLX) key functions
```c
#include  <mlx.h>

void  *
mlx_init();
```c
* mlx_init: Initialises the MLX library. Must be called before using any other functions.
* mlx_new_window: Creates a new window instance.
* mlx_hook: Registers events.
* mlx_loop: Loops over the MLX pointer, triggering each hook in order of registration.
* mlx_xpm_file_to_image: Converts an XPM file to an MLX image pointer.
* mlx_put_image_to_window: Puts your image to the screen at the given coordinates.
* mlx_destroy_image: Frees the image.
* mlx_destroy_window: Frees the window instance.
* mlx_destroy_display: Frees MLX.

