/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:08:07 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/16 21:40:51 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// Externo
# include <fcntl.h>//open, O_RDONLY
# include <unistd.h>//read, close, write
# include <stdlib.h>//malloc
# include <stdio.h>//printf

// Interno
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"
# include "libft/libft.h"

typedef struct s_game
{
    void    *mlx;
    void    *win;
    char    **map;
    int     map_width;
    int     map_height;
    int     player_x;
    int     player_y;
    int     collectibles;
    int     exit_x;
    int     exit_y;
    int     moves;
} t_game;

void    flood_fill(t_game *game, int x, int y, char target);
int     is_valid_path(t_game *game);
void    parse_map(t_game *game, char *file);

#endif