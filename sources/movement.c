/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 21:03:52 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/17 21:32:48 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	equal(t_game *game, int x, int y, char c)
{
	if (game->map[y][x] == c)
		return (1);
	return (0);
}
//ARREGLAR
void	ft_move(t_game *game, int x, int y)
{
	x += game->player_x;
	y += game->player_y;
	if (equal(game, x, y, '1'))
		return ;
	else if (equal(game, x, y, '0'))
		ft_walk(game, x, y);
	else if (equal(game, x, y, 'C'))
	{
		put_img(game, x, y, game->imgfloor);
		ft_walk(game, x, y);
		game->collect--;
		game->map[x][y] = '0';
		if (game->collect == 0)
		{
			put_img(game, x, y, game->imgfloor);
			put_img(game, x, y, game->imgplayer);
			put_img(game, game->exit_x, game->exit_y, game->imgexit);
		}
	}
	else if (equal(game, x, y, 'X') && game->collect == 0)
		ft_walk(game, x, y);
	else if (equal(game, x, y, 'X'))
		map_error(game, "Game Over", 0);
	ft_chage_player(game, x, y);
}