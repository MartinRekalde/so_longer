/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:42:04 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 17:14:23 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_char(t_game *game, char c)
{
	if ((c != '1' || c != '0' || c != 'C' || c != 'P' || c != 'E'))
	{
		map_error(game, "\nError, not recognized character in map.\n", 1);
		return (1);
	}
	return (0);
}

int	check_wall(t_game *game, char c)
{
	if (c != '1')
	{
		map_error(game, "\nError, map must be sorrounded by 1 (walls).\n", 1);
		return (1);
	}
	return (0);
}

int	walls_and_c(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
		game->collect++;
	if ((y == 0 || y == game->map_y - 1 || x == game->map_x - 2 || x == 0)
		&& (check_wall(game, game->map[y][x]) == 1))
		return (0);
	return (1);
}

int	check_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x] != '\n' && game->map[y][x] != '\0')
		{
			if (game->map[y][x] == '0' || game->map[y][x] == '1'
				|| game->map[y][x] == 'E' || game->map[y][x] == 'P'
				|| game->map[y][x] == 'C')
			{
				if (!walls_and_c(game, x, y))
					return (1);
			}
			else if (check_char(game, game->map[y][x]) == 1)
				return (1);
			x++;
		}
		y++;
	}
	if (game->collect == 0)
		map_error(game, "\nError, there must at least 1 collectible.\n", 1);
	return (0);
}
