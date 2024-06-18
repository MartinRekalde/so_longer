/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:08:07 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/18 17:38:10 by mrekalde         ###   ########.fr       */
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
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53

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

void	is_ber(char *argv);
void	start_game(t_game *game);
void	init_s_game(t_game *game);
void	open_map(char *filename, t_game *game);
void	is_rectangle(t_game *game);
void	player_position(char **map, t_game *game);
void	exit_position(char **map, t_game *game);
void	check_map(t_game *game);
void	check_wall(t_game *game);
void	finishable_map(t_game *game);
int		close_window(t_game *game);
void	buffer_error(char *message, int fd, char *buffer);
void	EP_error(char *message);
void	map_error(t_game *game, char *message, int error);

#endif