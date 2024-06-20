/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:51 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/20 20:22:33 by mrekalde         ###   ########.fr       */
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
		printf("\nError, read_map.\n");
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

	y = 0;
	error = 0;
	while (map[y])
	{
		x = 0;
		while(map[y][x])
		{
			if (map[y][x] == 'P')
			{
				error++;
				game->player_x = x;
				game->player_y = y;
			}
			x++;
		}
		y++;
	}
	if (error == 1)
		return ;
	else
		EP_error("\nError, invalid number of P\n");
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
		EP_error("\nError, invalid number of E\n");
}

void	get_map_xy(t_game *game)
{
	int	y;
	
	y = 0;
	game->map_x = ft_strlen(game->map[0]);
	while (game->map[y])
		y++;
	game->map_y = y;
}

int	check_char(t_game *game, char c)
{
	printf("--> c = %c", c);
	if ((c != '1' || c != '0' || c != 'C' || c != 'P' || c != 'E'))
	{
		map_error(game, "\nError, not recognized character in map.\n", 1);
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
				if (game->map[y][x] == 'C')
					game->collect++;
				if ((y == 0 || y == game->map_y || x == (game->map_x -1) || x == 0) && (check_wall(game, game->map[y][x]) == 1))
					return (1);
 			}
			else if(check_char(game, game->map[y][x]) == 1)
				return 1;
			x++;
		}
		y++;
	}
	if (game->collect == 0)
		map_error(game, "\nError, there must at least 1 collectible.\n", 1);
	return (0);
}
