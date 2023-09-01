/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: correia <correia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:42:23 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/01 09:04:15 by correia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
void	*new_file_img(char *path, t_win so_long)
{
	void	*img;

	img = mlx_xpm_file_to_image(so_long.mlx_ptr, path, &so_long.map->pos.w, &so_long.map->pos.h);
	if (!img)
		error(1); /* corrigir este erro*/
	return (img);
}

void	images(t_win *so_long)
{
	so_long->img->player = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/player_down.xpm", &so_long->map->width,
			&so_long->map->height);
	so_long->img->wall = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/wall.xpm", &so_long->map->width,
			&so_long->map->height);
	so_long->img->floor = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/floor.xpm", &so_long->map->width,
			&so_long->map->height);	
	so_long->img->collectible = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/collectible.xpm", &so_long->map->width,
			&so_long->map->height);	
	so_long->img->exit = mlx_xpm_file_to_image(so_long->mlx_ptr, "./xpm/exit1.xpm", &so_long->map->width,
			&so_long->map->height);
}
