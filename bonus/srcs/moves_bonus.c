/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:36:18 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/04 18:07:10 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	load_keys(int keycode, t_win *so_long)
{
	if (keycode == ESC)
		exit_so_long(so_long);
	else if (keycode == W)
		move_player_column(so_long, -1);
	else if (keycode == S)
		move_player_column(so_long, 1);
	else if (keycode == A)
		move_player_lines(so_long, -1);
	else if (keycode == D)
		move_player_lines(so_long, 1);
	return (0);
}

void	move_player_column(t_win *so_long, int y_move)
{
	t_pos	pos;

	pos = so_long->map.pos;
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->player);
	if (y_move == 1)
		so_long->img->player = insert_new_images(*so_long,
				"./xpm/player_down.xpm");
	else
		so_long->img->player = insert_new_images(*so_long,
				"./xpm/player_up.xpm");
	if (so_long->matrix[pos.h + y_move][pos.w] != '1' && so_long->matrix[pos.h
		+ y_move][pos.w] != 'E')
		move_up_down(so_long, y_move);
	else if (so_long->matrix[pos.h + y_move][pos.w] == 'E')
		exit_so_long(so_long);
	mlx_clear_window(so_long->mlx_ptr, so_long->win_ptr);
	draw_imgs(*so_long);
}

void	move_player_lines(t_win *so_long, int x_move)
{
	t_pos	pos;

	pos = so_long->map.pos;
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->player);
	if (x_move == 1)
		so_long->img->player = insert_new_images(*so_long,
				"./xpm/player_right.xpm");
	else
		so_long->img->player = insert_new_images(*so_long,
				"./xpm/player_left.xpm");
	if (so_long->matrix[pos.h][pos.w + x_move] != '1'
		&& so_long->matrix[pos.h][pos.w + x_move] != 'E')
		move_right_left(so_long, x_move);
	else if (so_long->matrix[pos.h][pos.w + x_move] == 'E')
		exit_so_long(so_long);
	mlx_clear_window(so_long->mlx_ptr, so_long->win_ptr);
	draw_imgs(*so_long);
}

void	move_up_down(t_win *so_long, int y_move)
{
	if (so_long->matrix[so_long->map.pos.h + y_move][so_long->map.pos.w] == 'C')
	{
		so_long->map.collectible--;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = '0';
		so_long->map.pos.h += y_move;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = 'P';
	}
	else if (so_long->matrix[so_long->map.pos.h
			+ y_move][so_long->map.pos.w] == '0')
	{
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = '0';
		so_long->map.pos.h += y_move;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = 'P';
	}
	else if (so_long->matrix[so_long->map.pos.h + y_move] \
	[so_long->map.pos.w] == 'M')
		exit_so_long(so_long);
	total_of_moves(so_long);
}

void	move_right_left(t_win *so_long, int x_move)
{
	if (so_long->matrix[so_long->map.pos.h][so_long->map.pos.w + x_move] == 'C')
	{
		so_long->map.collectible--;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = '0';
		so_long->map.pos.w += x_move;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = 'P';
	}
	else if (so_long->matrix[so_long->map.pos.h][so_long->map.pos.w \
	+ x_move] == '0')
	{
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = '0';
		so_long->map.pos.w += x_move;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = 'P';
	}
	else if (so_long->matrix[so_long->map.pos.h][so_long->map.pos.w + \
	x_move] == 'M')
		exit_so_long(so_long);
	total_of_moves(so_long);
}
