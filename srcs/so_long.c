/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/31 16:16:36 by pveiga-c         ###   ########.fr       */
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
	mlx_loop(so_long->mlx_ptr);
}

static void	put_img(t_win *so_long, void *img, int x, int y)
{
	mlx_put_image_to_window(so_long->mlx_ptr, so_long->win_ptr, img, x * 64, y * 64);
}

void	draw_imgs(t_win *so_long)
{
	int	i;
	int	j;

	i = 0;
	while (so_long->matrix[i])
	{
		j = 0;
		while (so_long->matrix[i][j])
		{
			if (so_long->matrix[i][j] == 'P')
				put_img(so_long, so_long->img->player, j, i);
			else if (so_long->matrix[i][j] == 'C')
				put_img(so_long, so_long->img->collectible, j, i);
			else if (so_long->matrix[i][j] == '1')
				put_img(so_long, so_long->img->wall, j, i);
			else if (so_long->matrix[i][j] == 'E')
				put_img(so_long, so_long->img->exit, j, i);
			else if (so_long->matrix[i][j] == '0')
				put_img(so_long, so_long->img->floor, j, i);
			j++;
		}
		i++;
	}
}

void	images(t_win *so_long)
{
	so_long->img->player = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/player_down.xpm", &so_long->map->width,
			&so_long->map->height);
	so_long->img->wall = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/wall1.xpm", &so_long->map->width,
			&so_long->map->height);
	so_long->img->floor = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/floor.xpm", &so_long->map->width,
			&so_long->map->height);	
	so_long->img->collectible = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/collectible.xpm", &so_long->map->width,
			&so_long->map->height);	
	so_long->img->exit = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/exit1.xpm", &so_long->map->width,
			&so_long->map->height);
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