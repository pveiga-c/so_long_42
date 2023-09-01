/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/01 20:50:07 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_win so_long)
{
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.width * 64,
			so_long.map.height * 64, "SO LONG");
	so_long.img = malloc(sizeof(t_img));
	insert_images(so_long);
	draw_imgs(so_long);
	mlx_hook(so_long.win_ptr, KeyRelease, KeyReleaseMask, load_keys, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask, exit_so_long, &so_long);
	mlx_loop(so_long.mlx_ptr);
}

int	exit_so_long(t_win *so_long)
{
	free_matrix(so_long->matrix);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->collectible);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->exit);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->player);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->floor);
	mlx_destroy_image(so_long->mlx_ptr, so_long->img->wall);
	free(so_long->mlx_ptr);
	exit(0);
}
int	load_keys(int keycode, t_win *so_long)
{
	if (keycode == ESC)
		exit_so_long(so_long);
	else if (keycode == W || keycode == UP)
		move_player_column(so_long, -1);
	else if (keycode == S || keycode == DOWN)
		move_player_column(so_long, 1);
	else if (keycode == A || keycode == RIGHT)
		move_player_lines(so_long, -1);
	else if (keycode == D || keycode == LEFT)
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
	else if(so_long->matrix[pos.h + y_move][pos.w] == 'E')
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
	else if(so_long->matrix[pos.h][pos.w + x_move] == 'E')
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
	else if (so_long->matrix[so_long->map.pos.h][so_long->map.pos.w
			+ x_move] == '0')
	{
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = '0';
		so_long->map.pos.w += x_move;
		so_long->matrix[so_long->map.pos.h][so_long->map.pos.w] = 'P';
	}
}

int	main(int argc, char **argv)
{
	t_win	so_long;

	if (argc == 2 && check_file(argv[1]))
	{
		// so_long->map = malloc(sizeof(t_map));
		// so_long.img = malloc(sizeof(t_img));
		// if (so_long.map == NULL)
		// {
		// 	perror("Erro ao alocar memoria.");
		// 	return (1);
		// }
		
		so_long.matrix = copy_map(argv[1], &so_long);
		check_copy_map(&so_long);
		check_map(so_long.matrix, &so_long.map, &so_long);
		game_init(so_long);
		free_matrix(so_long.matrix);
		free_matrix(so_long.temp_matrix);
	}
	return (0);
}


/*
prinf map

while (i != map->height)
	{
		j = 0;
		while (j != map->width)
		{
			printf("%c", so_long->temp_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
*/