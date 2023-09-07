/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/07 18:03:23 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

char	*path_img(int num)
{
	char	*str;

	if (num == 1)
		str = "./bonus/xpm/player_down.xpm";
	if (num == 2)
		str = "./bonus/xpm/wall.xpm";
	if (num == 3)
		str = "./bonus/xpm/floor.xpm";
	if (num == 4)
		str = "./bonus/xpm/exit.xpm";
	if (num == 5)
		str = "./bonus/xpm/player_up.xpm";
	if (num == 6)
		str = "./bonus/xpm/player_left.xpm";
	if (num == 7)
		str = "./bonus/xpm/player_right.xpm";
	if (num == 8)
		str = "./bonus/xpm/collectible.xpm";
	return (str);
}

void	images_check(t_win so_long)
{
	int		i;
	void	*img;

	i = 1;
	while (i != 9)
	{
		img = mlx_xpm_file_to_image(so_long.mlx_ptr, path_img(i), \
		&so_long.map.pos.w, &so_long.map.pos.h);
		if (!img)
			exit_so_long(&so_long);
		mlx_destroy_image(so_long.mlx_ptr, img);
		i++;
	}
	i = 1;
	while (i != 6)
	{
		img = mlx_xpm_file_to_image(so_long.mlx_ptr, path_img_enemy(i), \
		&so_long.map.pos.w, &so_long.map.pos.h);
		if (!img)
		{
			ft_printf("Error\nImage error.");
			exit_so_long(&so_long);
		}
		mlx_destroy_image(so_long.mlx_ptr, img);
		i++;
	}
}

void	game_init(t_win so_long)
{
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.width * 64,
			so_long.map.height * 64, "SO LONG");
	so_long.img = malloc(sizeof(t_img));
	so_long.moves_player = 0;
	values_init(so_long);
	images_check(so_long);
	insert_images(so_long);
	draw_imgs(so_long);
	mlx_hook(so_long.win_ptr, KeyRelease, KeyReleaseMask, load_keys, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, read_frame, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask, exit_so_long, \
	&so_long);
	mlx_loop(so_long.mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_win	so_long;

	if (argc != 2)
		error(11);
	if (argc == 2 && check_file(argv[1]))
	{
		check_new_line(argv[1]);
		so_long.matrix = copy_map(argv[1], &so_long);
		check_map(so_long.matrix, &so_long.map, &so_long);
		game_init(so_long);
		free_matrix(so_long.matrix);
		free_matrix(so_long.temp_matrix);
	}
	return (0);
}
