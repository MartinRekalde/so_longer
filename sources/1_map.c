/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:51 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 16:57:40 by mrekalde         ###   ########.fr       */
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
		ft_printf("\nError, read_map.\n");
	line = get_next_line(fd);
	if (!line)
		ep_error("\nError, map is empty.");
	h = 0;
	while (line)
	{
		h++;
		free(line);
		line = get_next_line(fd);
	}
	map = (char **)malloc(sizeof (char *) * (h + 2));
	map = fill_map(map, h, argv);
	return (close(fd), map);
}

void	player_position(char **map, t_game *game)
{
	int	x;
	int	y;
	int	error;

	y = 0;
	error = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
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
		ep_error("\nError, invalid number of P\n");
}

void	exit_position(char **map, t_game *game)
{
	int	x;
	int	y;
	int	error;

	x = 0;
	error = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
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
		ep_error("\nError, invalid number of E\n");
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
