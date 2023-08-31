/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/31 19:48:41 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_win *so_long)
{
	so_long->mlx_ptr = mlx_init();
	so_long->win_ptr = mlx_new_window(so_long->mlx_ptr, so_long->map->width * 64 ,
			so_long->map->height * 64, "SO LONG");
	so_long->img = malloc(sizeof(t_img));
	images(so_long);
	draw_imgs(so_long);
	mlx_hook(so_long->win_ptr, KeyRelease, KeyReleaseMask, load_keys, &so_long);
	mlx_loop(so_long->mlx_ptr);
}

int on_keypress(int keysym, t_win *so_long)
{
	(void)so_long;
	printf("Pressed key: %d\\n", keysym);
	return (0);
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
	else if(keycode == S)
		move_player(so_long);
	return (0);
}

void move_player(t_win *so_long)
{
	
}

int	main(int argc, char **argv)
{
	t_win	so_long;

	if (argc == 2 && check_file(argv[1]))
	{
		so_long.map = malloc(sizeof(t_map));
		so_long.img = malloc(sizeof(t_img));
		if (so_long.map == NULL)
		{
			perror("Erro ao alocar memoria.");
			return (1);
		}
		so_long.matrix = copy_map(argv[1], &so_long);
		check_map(so_long.matrix, so_long.map, &so_long);
		game_init(&so_long);
		
		free(so_long.map);
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