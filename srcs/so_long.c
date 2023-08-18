/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/18 19:07:56 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*
	S-LucasSerrano
*/
typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}			t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

int	draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY,
		int color)
{
	if (beginY == endY)
	{
		while (beginX != endX)
		{
			mlx_pixel_put(mlx, win, beginX, beginY, color);
			beginX++;
		}
	}
	else
	{
		while (beginX != endX && beginX != endY)
		{
			mlx_pixel_put(mlx, win, beginX, beginY, color);
			beginX++;
			beginY++;
		}
		beginY++;
	}
	return (0);
}

int	mouse_event(int button, int x, int y, void *param)
{
	ft_putnbr(button);
	return (0);
}

int	main(void)
{
	t_win	mlx;
	t_win	win;
	t_win	h;
	t_win	w;

	h.height = 300;
	w.width = 300;
	mlx.mlx_ptr = mlx_init();
	win.win_ptr = mlx_new_window(mlx.mlx_ptr, h.height, w.width, "so_long");
	mlx_pixel_put(mlx.mlx_ptr, win.win_ptr, h.height / 2, w.width / 2,
			0x5FFF05);
	draw_line(mlx.mlx_ptr, win.win_ptr, 10, 10, 290, 10, 0x5FFF05);
	draw_line(mlx.mlx_ptr, win.win_ptr, 20, 20, 280, 280, 0xFF6545);
	mlx_mouse_hook(win.win_ptr, &mouse_event, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
