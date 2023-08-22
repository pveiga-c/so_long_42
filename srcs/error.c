/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 18:44:28 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/22 20:07:43 by pveiga-c         ###   ########.fr       */
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
	exit(1);
}
