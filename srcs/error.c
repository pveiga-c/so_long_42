/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:44:28 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/23 19:08:38 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error(int num)
{
	if (num == 1)
		write(1, "Error: Map name has to end in .ber\n", 36);
	if (num == 2)
		write(1, "Error: Map has to be rectangular\n", 34);
	if (num == 3)
		write(1, "Error: The map must be closed/surrounded by walls\n", 51);
	if (num == 4)
		write(1, "Error: Number of players must be 1\n", 36);
	if (num == 5)
		write(1, "Error: Number of exits must be 1\n", 34);
	if (num == 6)
		write(1, "Error: Number of collectibles must be at least 1\n", 50);
	exit(num);
}

void	check_num_components(t_map	*map)
{
	if(map->player != 1)
		error(4);
	if(map->exit != 1)
		error(5);
	if(map->collectible < 1)
		error(6);
}