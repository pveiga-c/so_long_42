/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:44:28 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/07 17:53:40 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(int num)
{
	if (num == 1)
		ft_printf("Error\nMap name has to end in .ber\n");
	if (num == 2)
		ft_printf("Error\nMap has to be rectangular\n");
	if (num == 3)
		ft_printf("Error\nThe map must be closed/surrounded by walls\n");
	if (num == 4)
		ft_printf("Error\nNumber of players must be 1\n");
	if (num == 5)
		ft_printf("Error\nNumber of exits must be 1\n");
	if (num == 6)
		ft_printf("Error\nNumber of collectibles must be at least 1\n");
	if (num == 7)
		ft_printf("Error\nNo Solution on Map!\n");
	if (num == 8)
		ft_printf("Error\nMap does not exist\n");
	if (num == 9)
		ft_printf("Error\nEmpty file\n");
	if (num == 10)
		ft_printf("Error\nInvalid number of arguments!\n");
	if (num == 11)
		ft_printf("Error\nInvalid image!\n");
	if (num == 12)
		ft_printf("Error\nInvalid characters!\n");
	exit(num);
}

void	check_num_components(char **map_matrix, t_map *map)
{
	if (map->player != 1)
	{
		free_matrix(map_matrix);
		error(4);
	}
	if (map->exit != 1)
	{
		free_matrix(map_matrix);
		error(5);
	}
	if (map->collectible < 1)
	{
		free_matrix(map_matrix);
		error(6);
	}
}

void	free_matrix(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	exit_so_long(t_win *so_long)
{
	free_matrix(so_long->matrix);
	if (so_long->img->collectible)
		mlx_destroy_image(so_long->mlx_ptr, so_long->img->collectible);
	if (so_long->img->exit)
		mlx_destroy_image(so_long->mlx_ptr, so_long->img->exit);
	if (so_long->img->player)
		mlx_destroy_image(so_long->mlx_ptr, so_long->img->player);
	if (so_long->img->floor)
		mlx_destroy_image(so_long->mlx_ptr, so_long->img->floor);
	if (so_long->img->wall)
		mlx_destroy_image(so_long->mlx_ptr, so_long->img->wall);
	mlx_destroy_window(so_long->mlx_ptr, so_long->win_ptr);
	mlx_destroy_display(so_long->mlx_ptr);
	free(so_long->mlx_ptr);
	free(so_long->img);
	exit(0);
}

void	total_of_moves(t_win *so_long)
{
	so_long->moves_player++;
	ft_printf("Total of moves: %d\n", so_long->moves_player);
}
