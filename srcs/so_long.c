/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 17:05:55 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/21 19:57:14 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if(argc == 2 && check_file(argv[1]))
	{
		t_game so_long;
		int i;
		int j;

		i = 0;
		so_long.map.matrix = copy_map(argv[1]);
		check_map(so_long.map.matrix);
		/*while(i != 9)
		{
			j = 0;
			while(j != 22)
			{
				printf("%c", so_long.map.matrix[i][j]);
				j++;
			}
			printf("\n");
			i++;
		}*/
	}
	return (0);
}
