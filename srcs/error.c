/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:44:28 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/26 16:59:51 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(int num)
{
	if (num == 1)
		write(1, "Error\nMap name has to end in .ber\n", 35);
	if (num == 2)
		write(1, "Error\nMap has to be rectangular\n", 33);
	if (num == 3)
		write(1, "Error\nThe map must be closed/surrounded by walls\n", 50);
	if (num == 4)
		write(1, "Error\nNumber of players must be 1\n", 35);
	if (num == 5)
		write(1, "Error\nNumber of exits must be 1\n", 33);
	if (num == 6)
		write(1, "Error\nNumber of collectibles must be at least 1\n", 49);
	if (num == 7)
		write(1, "Error\nNo Solution on Map!\n", 27);
	exit(num);
}

void	check_num_components(char **map_matrix, t_map *map)
{
	if (map->player != 1)
	{
		free_matrix(map_matrix);
		free(map);
		error(4);
	}
	if (map->exit != 1)
	{
		free_matrix(map_matrix);
		free(map);
		error(5);
	}
	if (map->collectible < 1)
	{
		free_matrix(map_matrix);
		free(map);
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
