/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:08:07 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 16:41:48 by mrekalde         ###   ########.fr       */
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
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_game
{
	char	**map;
	char	**map_copy;
	void	*mlx;
	void	*win;
	int		map_x;
	int		map_y;
	int		player_x;
	int		player_y;
	int		x;
	int		y;
	int		collect;
	int		exit_x;
	int		exit_y;
	int		moves;
	int		count;
	void	*imgplayer;
	void	*imgfloor;
	void	*imgwall;
	void	*imgexit;
	void	*imgcollect;
}	t_game;

void	is_ber(char *argv);
void	start_game(t_game *game);
void	init_s_game(t_game *game);
char	**read_map(char *argv);
void	is_rectangle(t_game *game);
void	player_position(char **map, t_game *game);
void	exit_position(char **map, t_game *game);
int		check_map(t_game *game);
void	finishable_map(t_game *game);
int		move(t_game *game, int x, int y);
int		equal(t_game *game, int x, int y, char c);
void	put_img(t_game *game, int x, int y, void *img);
void	paint_map(t_game *game);
void	hook(t_game *game);
void	destroy_mlx(t_game *game);
void	get_xpm(t_game *game);
int		close_window(t_game *game);
void	get_map_xy(t_game *game);
void	ft_printf(char *str);
void	ep_error(char *message);
void	map_error(t_game *game, char *message, int error);

#endif