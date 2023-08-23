/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:48:17 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/23 15:35:48 by pveiga-c         ###   ########.fr       */
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
	temp_map = ft_calloc(1, 1);
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