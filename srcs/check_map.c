/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:32:20 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/23 15:38:30 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(char **map_matrix, t_map *map, t_win *so_long)
{
	check_retangular(map_matrix, map, so_long);
	check_walls(map_matrix, map, so_long);
}

void	check_retangular(char **map_matrix, t_map *map, t_win *so_long)
{
	int	i;

	map->width = ft_strlen(map_matrix[0]);
	i = 1;
	while (i != map->height)
	{
		if (ft_strlen(map_matrix[i]) == ft_strlen(map_matrix[0]))
			i++;
		else
			error(2);
	}
}

void	check_walls(char **map_matrix, t_map *map, t_win *so_long)
{
	int	i;

	i = 0;
	while (i != map->width)
	{
		if (map_matrix[0][i] == '1' && map_matrix[map->height - 1][i] == '1')
			i++;
		else
			error(3);
	}
	i = 1;
	while (i != map->height - 1)
	{
		if (map_matrix[i][0] == '1' && map_matrix[i][map->width] == '1')
			i++;
		else
			error(3);
	}
}
