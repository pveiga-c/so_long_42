/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:32:20 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/24 17:52:45 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map(char **map_matrix, t_map *map, t_win *so_long)
{
	check_retangular(map_matrix, map, so_long);
	check_walls(map_matrix, map, so_long);
	check_componentes(map_matrix, map, so_long);
	check_path(map_matrix, map, so_long);
	printf("ola estou aqui!!\n");
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
		if (map_matrix[i][0] == '1' && map_matrix[i][map->width - 1] == '1')
			i++;
		else
			error(3);
	}
}

void 	check_componentes(char **map_matrix, t_map *map, t_win *so_long)
{
	int i;
	int j;

	i = 1;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	while(i != map->height - 1)
	{
		j = 1;
		while(j != map->width - 1)
		{
			if(map_matrix[i][j] == 'P')
				map->player++;
			if(map_matrix[i][j] == 'E')
				map->exit++;
			if(map_matrix[i][j] == 'C')
				map->collectible++;
			j++;
		}
		i++;
	}
	check_num_components(map);
}

void	check_path(char **map_matrix, t_map *map, t_win *so_long)
{
	int i;
	int j;

	i = 0;
	copy_matrix(map_matrix, so_long);
	find_pos(map_matrix, map);
	flood_fill(so_long->temp_matrix, map, map->pos.h, map->pos.w);
	
	while(i != map->height)
	{
		j = 0;
		while (j != map->width)
		{
			printf("%c", so_long->temp_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	check_componentes_flood_fill(so_long->temp_matrix, map);
}	
void	find_pos(char **map_matrix, t_map *map)
{
	int i;
	int j;

	i = 1;
	while (i != map->height)
	{
		j = 0;
		while (j != map->width)
		{
			if(map_matrix[i][j] == 'P')
			{
				map->pos.h = i;
				map->pos.w = j;
				break;
			}
			j++;
		}
		i++;
	}
}
