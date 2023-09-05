/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 20:27:26 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/05 19:03:30 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	flood_fill(char **temp_matrix, t_map *map, int pos_h, int pos_w)
{
	if (check_pos_flood_fill(temp_matrix, map, pos_h + 1, pos_w))
		flood_fill(temp_matrix, map, pos_h + 1, pos_w);
	if (check_pos_flood_fill(temp_matrix, map, pos_h - 1, pos_w))
		flood_fill(temp_matrix, map, pos_h - 1, pos_w);
	if (check_pos_flood_fill(temp_matrix, map, pos_h, pos_w + 1))
		flood_fill(temp_matrix, map, pos_h, pos_w + 1);
	if (check_pos_flood_fill(temp_matrix, map, pos_h, pos_w - 1))
		flood_fill(temp_matrix, map, pos_h, pos_w - 1);
}

int	check_pos_flood_fill(char **temp_matrix, t_map *map, int pos_h, int pos_w)
{
	if (pos_h < 0 || pos_h >= map->height || pos_w < 0 || pos_w >= map->width)
		return (0);
	if (temp_matrix[pos_h][pos_w] == 'E')
		temp_matrix[pos_h][pos_w] = '1';
	if (temp_matrix[pos_h][pos_w] != '1' && temp_matrix[pos_h][pos_w] != 'X')
	{
		temp_matrix[pos_h][pos_w] = 'X';
		return (1);
	}
	return (0);
}

void	check_componentes_flood_fill(char **map_matrix, char **temp_matrix,
		t_map *map)
{
	int		i;
	int		j;
	char	exit;
	char	collectible;

	i = 1;
	while (i != map->height - 1)
	{
		j = 1;
		while (j != map->width - 1)
		{
			if (temp_matrix[i][j] == 'E' || temp_matrix[i][j] == 'C')
			{
				free_matrix(temp_matrix);
				free_matrix(map_matrix);
				error(7);
			}
			j++;
		}
		i++;
	}
	free_matrix(temp_matrix);
}
