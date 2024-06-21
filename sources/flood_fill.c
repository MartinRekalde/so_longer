/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:56:13 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 16:58:41 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	flood_map(t_game *game, int x, int y)
{
	if ((game->map_copy[x][y] == 'C'
		|| game->map_copy[x][y] == 'E') && game->map_copy[x][y])
		game->count++;
	if (game->map_copy[x][y] != '1'
		&& game->map_copy[x][y] != 'X' && game->map_copy[x][y])
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
		map_error(game, "\nError, the map isn't finishable\n", 1);
}
