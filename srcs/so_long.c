/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/26 15:45:07 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_win	so_long;

	if (argc == 2 && check_file(argv[1]))
	{
		so_long.map = malloc(sizeof(t_map));
		if(so_long.map == NULL)
		{
			perror("Erro ao alocar memoria.");
			return (1);
		}
		so_long.matrix = copy_map(argv[1], &so_long);
		check_map(so_long.matrix, so_long.map, &so_long);
		printf("ola estou aqui!!\n");
		free(so_long.map);
		free_matrix(so_long.matrix);
		free_matrix(so_long.temp_matrix);
	}
	return (0);
}
