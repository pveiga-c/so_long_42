/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:32:20 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/09/07 18:03:44 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_map(char **map_matrix, t_map *map, t_win *so_long)
{
	int	i;
	int	j;
	
	i = 0;
	map->width = ft_strlen(map_matrix[0]);
	while(i != map->height)
	{
		j = 0;
		while(j != map->width)
		{
			if(map_matrix[i][j] != '1' && map_matrix[i][j] != '0' \
			&& map_matrix[i][j] != 'E' && map_matrix[i][j] != 'C' \
			&& map_matrix[i][j] != 'P' && map_matrix[i][j] != 'M')
			{
				free_matrix(map_matrix);
				error(12);
			}
			j++;
		}
		i++;
	}
	check_retangular(map_matrix, map, so_long);
	check_walls(map_matrix, map, so_long);
	check_componentes(map_matrix, map, so_long);
	check_path(map_matrix, map, so_long);
}

void	check_retangular(char **map_matrix, t_map *map, t_win *so_long)
{
	int	i;

	map->width = ft_strlen(map_matrix[0]);
	i = 1;
	while (i != map->height)
	{
		if (ft_strlen(map_matrix[i]) == ft_strlen(map_matrix[0])
			&& map_matrix[i][0] != '\n')
			i++;
		else
		{
			free_matrix(map_matrix);
			error(2);
		}
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
		{
			free_matrix(map_matrix);
			error(3);
		}
	}
	i = 1;
	while (i != map->height - 1)
	{
		if (map_matrix[i][0] == '1' && map_matrix[i][map->width - 1] == '1')
			i++;
		else
		{
			free_matrix(map_matrix);
			error(3);
		}
	}
}

void	check_componentes(char **map_matrix, t_map *map, t_win *so_long)
{
	int	i;
	int	j;

	i = 0;
	map->player = 0;
	map->exit = 0;
	map->collectible = 0;
	map->enemy = 0;
	while (++i != map->height - 1)
	{
		j = 1;
		while (j != map->width - 1)
		{
			if (map_matrix[i][j] == 'P')
				map->player++;
			if (map_matrix[i][j] == 'E')
				map->exit++;
			if (map_matrix[i][j] == 'C')
				map->collectible++;
			if (map_matrix[i][j] == 'M')
				map->enemy++;
			j++;
		}
	}
	check_num_components(map_matrix, map);
}

void	check_path(char **map_matrix, t_map *map, t_win *so_long)
{
	int	i;
	int	j;

	i = 0;
	copy_matrix(map_matrix, so_long);
	find_pos(map_matrix, map);
	flood_fill(so_long->temp_matrix, map, map->pos.h, map->pos.w);
	check_componentes_flood_fill(map_matrix, so_long->temp_matrix, map);
}
