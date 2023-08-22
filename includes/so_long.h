/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:54:44 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/22 20:30:28 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int     width;
	int		height;
	
}			t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
    char	**matrix;
	t_map	*map;
}			t_win;

/*  error  */
void		error(int num);

/* checks */

int			check_file(char *av);
char		**copy_map(char *av, t_win *so_long);
void		check_map(char **map_matrix, t_map *map, t_win *so_long);
#endif