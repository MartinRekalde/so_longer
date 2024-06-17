/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:08:07 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/17 20:43:07 by mrekalde         ###   ########.fr       */
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

# define AVATAR "textures/ducky_alone.xpm"
# define WALL "textures/wall.xpm"
# define FLOOR "textures/floor.xpm"
# define EXIT "textures/ducky_alone.xpm"
# define COLLECT "textures/ducky_alone.xpm"

typedef struct s_game
{
	char    **map;
	char	**map_copy;
	void    *mlx;
	void    *win;
	int     map_x;
	int     map_y;
	int     player_x;
	int     player_y;
	int		x;
	int		y;
	int     collect;
	int     exit_x;
	int     exit_y;
	int     moves;
	int		count;
	void	*imgplayer;
	void	*imgfloor;
	void	*imgwall;
	void	*imgexit;
	void	*imgcollect;
} t_game;


#endif