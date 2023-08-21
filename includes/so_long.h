/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pveiga-c <pveiga-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:54:44 by pveiga-c          #+#    #+#             */
/*   Updated: 2023/08/21 19:41:31 by pveiga-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "..//libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map {
    char **matrix;
    
} t_map;


typedef struct s_game {
    void *mlx_ptr;
    void *win_ptr;
    t_map map;
} t_game;

/*  error  */
void error(int num);

 /* checks */

int	check_file(char *av);
char **copy_map(char *av);
void check_map(t_game **map);

#endif