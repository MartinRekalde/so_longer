/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:51 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/18 22:02:38 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"



char	**fill_map(char **map, int h, char *argv)
{
	int	i;
	int	fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	while (h > i)
		map[i++] = get_next_line(fd);
	map[i] = NULL;

	close (fd);
	return (map);
}

char	**read_map(char *argv)
{
	int		fd;
	int		h;
	int		w;
	char	*line;
	char	**map;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		printf("error, read_map.\n");
	line = get_next_line(fd);
	w = ft_strlen(line);
	h = 0;
	while (line)
	{
		h++;
		free(line);
		line = get_next_line(fd);
	}
	map = (char **)malloc(sizeof (char *) * (h * w));
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

void	check_map(t_game *game)
{
	int	x;
	int y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			//printf("%c", game->map[x][y]);
			if (game->map[x][y] == 'C')
				game->collect++;
			else if (game->map[x][y] != '0' && game->map[x][y] != '1' && game->map[x][y] != 'E' && game->map[x][y] != 'P')
				map_error(game, "\nOnly 01CEP characters admited\n", 1);
			y++;
		}
		x++;
	}
	if (game->collect == 0)
		map_error(game, "Error, there must at least 1 collectible", 1);
}

void	check_wall(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->map_y)
	{
		if (game->map[x][0] != '1' || game->map[x][game->map_y - 1] != '1')
			map_error(game, "No walls on the first and/or last line.", 1);
		x++;
	}
	while (x < game->map_x)
	{
		if (game->map[y][0] != '1' || game->map[y][game->map_x - 1] != '1')
			map_error(game, "No walls on the first and/or last column.", 1);
		y++;
	}
}
