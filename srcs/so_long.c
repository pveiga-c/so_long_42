/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/02 15:36:30 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	game_init(t_win so_long)
{
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.width * 64,
			so_long.map.height * 64, "SO LONG");
	so_long.img = malloc(sizeof(t_img));
	so_long.moves_player = 0;
	insert_images(so_long);
	draw_imgs(so_long);
	mlx_hook(so_long.win_ptr, KeyRelease, KeyReleaseMask, load_keys, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask, exit_so_long, &so_long);
	mlx_loop(so_long.mlx_ptr);
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
		// check_copy_map(&so_long);
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