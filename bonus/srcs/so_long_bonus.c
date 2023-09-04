/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/04 08:59:51 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	game_init(t_win so_long)
{
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.width * 64,
			so_long.map.height * 64, "SO LONG");
	so_long.img = malloc(sizeof(t_img));
	so_long.moves_player = 0;
	so_long.enemy = 0,
	so_long.enemy = spawn_enemies(so_long);	
	insert_images(so_long);
	draw_imgs(so_long);
	mlx_hook(so_long.win_ptr, KeyRelease, KeyReleaseMask, load_keys, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, spawn_enemies, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask, exit_so_long, &so_long);
	mlx_loop(so_long.mlx_ptr);
}
/*void	enemy(t_win	*sio_long)
{
	
}*/

char	*spawn_enemies(t_win	so_long)
{
	//int	i;

	//enemies = malloc(sizeof(char) * so_long.map->enemy);
	//i = so_long.map->enemy - 1;
	display_status(&so_long);
/*
	while(i >= 0)
	{
		
	}*/
}

void	display_status(t_win *so_long)
{
	char	*str;

	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 32, 33, 0x00000000, "Player moves: ");
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 32, 32, 0x00FFFFFF, "Player moves: ");
	str = ft_itoa(so_long->moves_player);
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 96, 33, 0x00000000,str);
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 96, 32, 0x00FFFFFF, str);
	free (str);
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 32, 49, 0x00000000, "Steps taken: ");
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 32, 48, 0x00FFFFFF, "Steps taken: ");
	str = ft_itoa(so_long->map.collectible);
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 120, 49, 0x00000000, str);
	mlx_string_put (so_long->mlx_ptr, so_long->win_ptr, 120, 48, 0x00FFFFFF, str);
	free (str);
}

int	main(int argc, char **argv)
{
	t_win	so_long;

	if (argc == 2 && check_file(argv[1]))
	{
		so_long.matrix = copy_map(argv[1], &so_long);
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