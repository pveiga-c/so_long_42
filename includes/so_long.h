/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:54:44 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/26 15:24:49 by pveiga-c         ###   ########.fr       */
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

typedef struct s_pos
{
	int		h;
	int		w;
}			t_pos;

typedef struct s_map
{
	int		width;
	int		height;
	int		player;
	int		exit;
	int		collectible;
	t_pos	pos;

}			t_map;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**matrix;
	char	**temp_matrix;
	t_map	*map;
}			t_win;

/*  error  */
void		error(int num);

/* checks */

int			check_file(char *av);
char		**copy_map(char *av, t_win *so_long);
void		copy_matrix(char **map_matrix, t_win *so_long);
void		find_pos(char **map_matrix, t_map *map);

/* check_map */

void		check_map(char **map_matrix, t_map *map, t_win *so_long);
void		check_retangular(char **map_matrix, t_map *map, t_win *so_long);
void		check_walls(char **map_matrix, t_map *map, t_win *so_long);
void		check_componentes(char **map_matrix, t_map *map, t_win *so_long);
void		check_path(char **map_matrix, t_map *map, t_win *so_long);

/* error */

void		error(int num);
void		check_num_components(char **map_matrix, t_map *map);
void		free_matrix(char **str);

/* flood_fill */

void		flood_fill(char **map_matrix_temp, t_map *map, int pos_w,
				int pos_h);
int			check_pos_flood_fill(char **temp_matrix, t_map *map, int pos_h,
				int pos_w);
void		check_componentes_flood_fill(char **map_matrix,char **temp_matix, t_map *map);

#endif