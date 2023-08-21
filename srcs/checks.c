/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:48:17 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/21 19:56:54 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_file(char *av)
{
	int i;

	i = ft_strlen(av) - 1;
	if(av[i] == 'r' && av[i - 1] == 'e' && av[i - 2] == 'b' && av[i - 3] == '.' && av[i - 4])		
		return (1);
	return (0);	
}

char **copy_map(char *av)
{
	int fd;
	char *temp;
	char *line;
	char **map_matrix;

	fd = open(av, O_RDONLY);
	if(fd == -1)
		return (NULL);
	temp = NULL;
	
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		temp = ft_strjoin(temp, line);
		free(line);	
	}
	map_matrix = ft_split(temp, '\n');
	free(temp);
	return (map_matrix);
}

void    check_map(t_game **map)
{
	int len;
	//int i;

   len = ft_strlen(map[0]);
   printf("%d", len); 
}