/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:18:51 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/17 19:40:41 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	open_file(char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
	{
		printf("Error, file can't be opened\n");
		close(fd);
		exit(1);
	}
	return (fd);
}

void	open_map(char *ber, t_game *game)
{
	int		fd;
	char	*buffer;
	int		i;
	
	i = 0;
	fd = open_file(ber);
	buffer = malloc(BUFFER_SIZE * sizeof(char));
	read(fd, buffer, BUFFER_SIZE);
	if (buffer[0] == '\0' || buffer[0] == '\n')
		buffer_error("Error, the map is too small.", fd, buffer);
	while (buffer[i])
	{
		if ((buffer[i] == '\n' && buffer[i + 1] == '\n') || (buffer[i] == '\n' && buffer[i + 1] == '\0'))
				buffer_error("Error, the map is incorrect.", fd, buffer);
		i++;
	}
	game->map = ft_split(buffer, '\n');
	game->map_copy = ft_split(buffer, '\n');
	free(buffer);
	close(fd);
}

void	player_position(char **map, t_game *game)
{
	int	x;
	int	y;
	int error;

	x = 0;
	error = 1;
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
		return (0);
	else
		EP_error("Error, invalid number of P");
}

void	exit_position(char **map, t_game *game)
{
	int	x;
	int	y;
	int error;

	x = 0;
	error = 1;
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
	if (error == 0)
		return (0);
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
			if (game->map[x][y] == 'C')
				game->collect++;
			else if (game->map[x][y] != '0' && game->map[x][y] != '1' && game->map[x][y] != 'E' && game->map[x][y] != 'P')
				map_error(game, "Only 01CEP characters admited", 1);
			y++;
		}
		x++;
	}
	if (game->collect == 0);
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
