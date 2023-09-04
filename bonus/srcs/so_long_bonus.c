/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/04 18:05:14 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	read_frame(t_win *so_long)
{
	if (so_long->frame > 6)
		so_long->frame = 1;
	if (so_long->frame == 1)
		so_long->img->enemy = insert_new_images(*so_long, \
		"./bonus/xpm/enemy1.xpm");
	else if (so_long->frame == 2)
		so_long->img->enemy = insert_new_images(*so_long, \
		"./bonus/xpm/enemy2.xpm");
	else if (so_long->frame == 3)
		so_long->img->enemy = insert_new_images(*so_long, \
		"./bonus/xpm/enemy3.xpm");
	else if (so_long->frame == 4)
		so_long->img->enemy = insert_new_images(*so_long, \
		"./bonus/xpm/enemy4.xpm");
	else if (so_long->frame == 5)
		so_long->img->enemy = insert_new_images(*so_long, \
		"./bonus/xpm/enemy5.xpm");
	else if (so_long->frame == 6)
		so_long->img->enemy = insert_new_images(*so_long, \
		"./bonus/xpm/enemy6.xpm");
	usleep(100000);
	so_long->frame++;
	draw_imgs(*so_long);
	return (0);
}

void	game_init(t_win so_long)
{
	so_long.mlx_ptr = mlx_init();
	so_long.win_ptr = mlx_new_window(so_long.mlx_ptr, so_long.map.width * 64,
			so_long.map.height * 64, "SO LONG");
	so_long.img = malloc(sizeof(t_img));
	insert_images(so_long);
	draw_imgs(so_long);
	mlx_hook(so_long.win_ptr, KeyRelease, KeyReleaseMask, load_keys, &so_long);
	mlx_loop_hook(so_long.mlx_ptr, read_frame, &so_long);
	mlx_hook(so_long.win_ptr, DestroyNotify, StructureNotifyMask, exit_so_long, \
	&so_long);
	mlx_loop(so_long.mlx_ptr);
}

void	display_status(t_win *so_long)
{
	char	*str;

	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 32, 22, 0x00FF00, \
	"Player moves: ");
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 32, 21, 0x00FF00, \
	"Player moves: ");
	str = ft_itoa(so_long->moves_player);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 120, 22, 0x00FF00, str);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 120, 21, 0x00FF00, str);
	free(str);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 32, 38, 0x00FF00, \
	"Tokens : ");
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 32, 37, 0x00FF00, \
	"Tokens : ");
	str = ft_itoa(so_long->map.collectible);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 120, 41, 0x00FF00, str);
	mlx_string_put(so_long->mlx_ptr, so_long->win_ptr, 120, 40, 0x00FF00, str);
	free(str);
}

void	values_init(t_win *so_long)
{
	so_long->moves_player = 0;
	so_long->enemy = 0;
}

int	main(int argc, char **argv)
{
	t_win	so_long;

	if (argc == 2 && check_file(argv[1]))
	{
		check_new_line(argv[1]);
		so_long.matrix = copy_map(argv[1], &so_long);
		check_map(so_long.matrix, &so_long.map, &so_long);
		values_init(&so_long);
		game_init(so_long);
		free_matrix(so_long.matrix);
		free_matrix(so_long.temp_matrix);
	}
	return (0);
}
