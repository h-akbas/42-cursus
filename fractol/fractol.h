/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:13:43 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/18 00:03:12 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stddef.h>

# define WIDTH 960
# define HEIGHT 640
# define USAGE "Error!\nUsage: \t./fractol mandelbrot\n\t./fractol julia\n\t\
./fractol burningship\n"

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	int				r_start;
	int				g_start;
	int				b_start;
	int				r_end;
	int				g_end;
	int				b_end;
}					t_color;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_zoom
{
	double	scale;
	int		x;
	int		y;
	int		iter;
	int		max_iter;
}				t_zoom;

typedef struct s_complex
{
	double	r;
	double	i;
}				t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;

	double	x_scale;
	double	y_scale;
	double	x_trans;
	double	y_trans;

	t_img	*img;
	t_color	*color;
	t_zoom	zoom;

	int		iter;
	int		max_iter;

	double	zoom_x;
	double	zoom_y;
	double	x_pos;
	double	y_pos;

	int		pos;
	int		fractal;
	int		h;
}				t_data;

size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		*ft_putendl_fd(char *s, int fd);
int			is_hexa(char c);
int			ft_atoi_hex(const char *str);
char		*fill_color(char *r, char *g, char *b);
char		*dec_to_hex(unsigned int num);
int			convert_colors(int red, int green, int blue);
t_data		*init_data(void);
void		set_value(t_data *data);
void		mandelbrot(t_data *data);
void		julia(t_data *data);
void		burning_ship(t_data *data);
void		mandel_px(t_data *data);
void		julia_px(t_data *data);
void		burning_px(t_data *data);
int			mandel_iter(t_complex z, int x, int y, t_data *data);
int			julia_iter(t_complex c, int x, int y, t_data *data);
int			burning_iter(t_complex z, int x, int y, t_data *data);
int			color_pixel(t_data *data);
void		px_img(t_data *data, int x, int y, int color);
int			key_hook(int keycode, t_data *data);
int			mouse_hook(int button, int x, int y, t_data *data);
int			get_mouse_pos(int x, int y, t_data *data);
int			handle_no_hook(t_data *data);
void		handle_key_hook(int keycode, t_data *data);
void		handle_mouse_hook(int button, int x, int y, t_data *data);
int			handle_cross_sign(t_data *data);
void		show_instructions(t_data *data);

#endif
