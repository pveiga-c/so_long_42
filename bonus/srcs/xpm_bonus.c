/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:42:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/04 18:11:51 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	put_img(t_win so_long, void *img, int x, int y)
{
	mlx_put_image_to_window(so_long.mlx_ptr, so_long.win_ptr, img, x * 64, y \
	* 64);
}

void	draw_imgs(t_win so_long)
{
	int	i;
	int	j;

	i = -1;
	while (so_long.matrix[++i])
	{
		j = -1;
		while (so_long.matrix[i][++j])
		{
			put_img_2(so_long, i, j);
		}
	}
	display_status(&so_long);
}

void	put_img_2(t_win so_long, int i, int j)
{
	if (so_long.matrix[i][j] == 'P')
		put_img(so_long, so_long.img->player, j, i);
	else if (so_long.matrix[i][j] == 'C')
		put_img(so_long, so_long.img->collectible, j, i);
	else if (so_long.matrix[i][j] == '1')
		put_img(so_long, so_long.img->wall, j, i);
	else if (so_long.matrix[i][j] == 'E' &&
				so_long.map.collectible == 0)
		put_img(so_long, so_long.img->exit, j, i);
	else if (so_long.matrix[i][j] == 'E' &&
				so_long.map.collectible != 0)
		put_img(so_long, so_long.img->floor, j, i);
	else if (so_long.matrix[i][j] == '0')
		put_img(so_long, so_long.img->floor, j, i);
	else if (so_long.matrix[i][j] == 'M')
		put_img(so_long, so_long.img->enemy, j, i);
}

void	*insert_new_images(t_win so_long, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(so_long.mlx_ptr, path, &so_long.map.pos.w,
			&so_long.map.pos.h);
	if (!img)
		error(9);
	return (img);
}

void	insert_images(t_win so_long)
{
	so_long.img->player = insert_new_images(so_long, \
	"./bonus/xpm/player_down.xpm");
	so_long.img->wall = insert_new_images(so_long, "./bonus/xpm/wall.xpm");
	so_long.img->floor = insert_new_images(so_long, "./bonus/xpm/floor.xpm");
	so_long.img->collectible = insert_new_images(so_long, \
	"./bonus/xpm/collectible.xpm");
	so_long.img->exit = insert_new_images(so_long, "./bonus/xpm/exit.xpm");
	so_long.img->enemy = insert_new_images(so_long, "./bonus/xpm/enemy1.xpm");
}
