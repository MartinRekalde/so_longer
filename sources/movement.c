/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:03:52 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 18:25:05 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	equal(t_game *game, int x, int y, char c)
{
	if (game->map[y][x] == c)
		return (1);
	return (0);
}

void	walk(t_game *game, int x, int y)
{
	game->moves++;
	printf("\nMove number: %i", game->moves);
	put_img(game, x, y, game->imgplayer);
	game->map[y][x] = '0';
}

int	move(t_game *game, int x, int y)
{
	printf("collectables: %i", game->collect);
	x = game->player_x + x;
	y = game->player_y + y;
	if (equal(game, x, y, '1') || (equal(game, x, y, 'E')
			&& game->collect != 0))
		return (0);
	put_img(game, game->player_x, game->player_y, game->imgfloor);
	if (equal(game, x, y, '0'))
		walk(game, x, y);
	else if (equal(game, x, y, 'P'))
		walk(game, x, y);
	else if (equal(game, x, y, 'C'))
	{
		walk(game, x, y);
		if (game->collect != 0)
			game->collect--;
	}
	else if (equal(game, x, y, 'E') && game->collect == 0)
	{
		walk(game, x, y);
		map_error(game, "\n¿You Won?\n", 0);
	}
	game->player_x = x;
	game->player_y = y;
	return (0);
}
