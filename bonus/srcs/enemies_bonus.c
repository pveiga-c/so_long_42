/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:19:40 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/05 19:22:03 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	read_frame(t_win *so_long)
{
	if (so_long->frame > 5)
		so_long->frame = 1;
	if (so_long->img->enemy)
		mlx_destroy_image(so_long->mlx_ptr, so_long->img->enemy);
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
	usleep(100000);
	so_long->frame++;
	draw_imgs(*so_long);
	return (0);
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
	so_long->frame = 1;
}
