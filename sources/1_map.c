/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:51 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/19 22:09:09 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



char	**fill_map(char **map, int h, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (h >= i)
		map[i++] = get_next_line(fd);
	map[i] = "\n";
	close (fd);
	return (map);
}

char	**read_map(char *argv)
{
	int		fd;
	int		h;

	char	*line;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		printf("error, read_map.\n");
	line = get_next_line(fd);
	
	h = 0;
	while (line)
	{
		h++;
		free(line);
		line = get_next_line(fd);
	}
	map = (char **)malloc(sizeof (char *) * (h + 2)) ;
	map = fill_map(map, h, argv);
	return (close(fd), map);
}

void	player_position(char **map, t_game *game)
{
	int	x;
	int	y;
	int error;

	x = 0;
	error = 0;
	while (map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if (map[x][y] == 'P')
			{
				error++;
				game->player_x = x;
				game->player_y = y;
			}
			y++;
		}
		x++;
	}
	if (error == 1)
		return ;
	else
		EP_error("Error, invalid number of P");
}

void	exit_position(char **map, t_game *game)
{
	int	x;
	int	y;
	int error;

	x = 0;
	error = 0;
	while (map[x])
	{
		y = 0;
		while(map[x][y])
		{
			if (map[x][y] == 'E')
			{
				error++;
				game->exit_x = x;
				game->exit_y = y;
			}
			y++;
		}
		x++;
	}
	if (error == 1)
		return ;
	else
		EP_error("Error, invalid number of E");
}

void	get_map_xy(t_game *game)
{
	//
	// CUIDADO CON LOS SALTOS DE LINEA MIRA A VER SI TE AFECTA EN ALGO, PROBABLEMENTE SI
	//
	
	int	y;
	
	y = 0;
	game->map_x = ft_strlen(game->map[0]);
	printf("x -- -- -- - >%d", game->map_x);
	while (game->map[y])
		y++;
	game->map_y = y;
}
int	check_bullshit(t_game *game, char c)
{
	printf("--> c = %c", c);
	if ((c != '1' || c != '0' || c != 'C' || c != 'P' || c != 'E'))
	{
		map_error(game, "\nescribe bien inutil .\n", 1);
		return (1);
	}
	return 0;
}

int	check_wall(t_game *game, char c)
{
	if(c != '1')
	{
		map_error(game, "\nError, map must be sorrounded by 1 (walls).\n", 1);
		return (1);
	}
	return 0;
}

int	check_map(t_game *game)
{
	int	x;
	int y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '0' || game->map[y][x] == '1' || game->map[y][x] == 'E' || game->map[y][x] == 'P'|| game->map[y][x] == 'C')
			{
				printf("x--->%d mapx--->%d\n", x, game->map_x);
				if (game->map[y][x] == 'C')
					game->collect++;
				if ((y == 0 || y == game->map_y || x == (game->map_x -1) || x == 0))
					if (check_wall(game, game->map[y][x]) == 1)
						return (1);
			}
			else if(check_bullshit(game, game->map[y][x]) == 1)
				return 1;
			x++;
		}
		y++;
	}
	if (game->collect == 0)
		map_error(game, "\nError, there must at least 1 collectible.\n", 1);
	return (0);
}
