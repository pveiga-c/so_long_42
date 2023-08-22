/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:48:17 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/22 20:29:40 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file(char *av)
{
	int	i;

	i = ft_strlen(av) - 1;
	if (av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b' && av[i - 3] == '.'
		&& av[i - 4])
		return (1);
	else
		error(1);
	return (0);
}

char	**copy_map(char *av, t_win *so_long)
{
	int		fd;
	char	*line;
	char	**map_matrix;
	char	*temp_map;
	int		h;

	h = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	temp_map = ft_calloc(1,1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_map = ft_strjoin(temp_map, line);
		free(line);
		h++;
	}
	so_long->map->height = h;
	map_matrix = ft_split(temp_map, '\n');
	free(temp_map);
	close(fd);
	return (map_matrix);
}

void	check_map(char **map_matrix, t_map *map, t_win *so_long)
{
	int i;
	
	map->width = ft_strlen(map_matrix[0]);
	i = 1;
	while (i != map->height)
	{
		if(ft_strlen(map_matrix[i]) == ft_strlen(map_matrix[0]))
			i++;
		else
			error(2);
	}
	i = 0;
	while(i != map->width)
	{
		if(map_matrix[0][i] == '1' && map_matrix[map->height - 1][i] == '1')
			i++;
		else
			error(3);
	}
	
		
}
