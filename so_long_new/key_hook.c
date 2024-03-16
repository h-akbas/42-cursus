/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:33:03 by hakbas            #+#    #+#             */
/*   Updated: 2024/03/16 19:02:18 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "mlx/mlx.h"
#include "so_long.h"

static void	render_player(t_data *data);
static void	move(int key_code, t_data *data);
static void	put_move_count(int count);
static void put_coll_count(int count);

int	key_hook(int key_code, t_data *d)
{
	if (key_code == UP && d->map->grid[d->pos.y - 1][d->pos.x] != '1')
		move(key_code, d);
	else if (key_code == LEFT && d->map->grid[d->pos.y][d->pos.x - 1] != '1')
		move(key_code, d);
	else if (key_code == DOWN && d->map->grid[d->pos.y + 1][d->pos.x] != '1')
		move(key_code, d);
	else if (key_code == RIGHT && d->map->grid[d->pos.y][d->pos.x + 1] != '1')
		move(key_code, d);
	else if (key_code == ESC)
		clean_exit(d);
	return (0);
}

static void	put_move_count(int count)
{
	ft_putstr_fd("Move count: ", 1);
	ft_putnbr_fd(count, 1);
	ft_putchar_fd('\n', 1);
}

static void put_coll_count(int count)
{
	ft_putstr_fd("Collectible count: ", 1);
	ft_putnbr_fd(count, 1);
	ft_putchar_fd('\n', 1);
}

static void	render_player(t_data *d)
{
	d->player_moves++;
	put_move_count(d->player_moves);
	if (d->map->grid[d->pos.y][d->pos.x] == 'C')
	{
		d->map->grid[d->pos.y][d->pos.x] = '0';
		d->coll--;
		put_coll_count(d->coll);
	}
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	render(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr,
		d->img[PLAYER], d->pos.x * WIDTH, d->pos.y * HEIGHT);
	if (d->map->grid[d->pos.y][d->pos.x] == 'E' && d->coll == 0)
	{
		ft_putendl_fd("YOU WIN", 1);
		clean_exit(d);
	}
}

static void	move(int key_code, t_data *data)
{
	if (key_code == UP)
	{
		data->pos.y--;
		render_player(data);
	}
	else if (key_code == DOWN)
	{
		data->pos.y++;
		render_player(data);
	}
	else if (key_code == LEFT)
	{
		data->pos.x--;
		render_player(data);
	}
	else if (key_code == RIGHT)
	{
		data->pos.x++;
		render_player(data);
	}
}
