/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:42:04 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/18 19:30:16 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void	flood_map(t_game *game, int x, int y)
{
	if ((game->map_copy[x][y] == 'C' || game->map_copy[x][y] == 'E') && game->map_copy[x][y])
		game->count++;
	if (game->map_copy[x][y] != '1' && game->map_copy[x][y] != 'X' && game->map_copy[x][y])
	{
		game->map_copy[x][y] = '1';
		flood_map(game, x + 1, y);
		flood_map(game, x - 1, y);
		flood_map(game, x, y + 1);
		flood_map(game, x, y - 1);
	}
}

void	finishable_map(t_game *game)
{
	game->x = game->player_x;
	game->y = game->player_y;
	flood_map(game, game->x, game->y);
	if (game->count != game->collect + 1)
		map_error(game, "The map isn't finishable", 1);
}

