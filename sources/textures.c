/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:53:28 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/20 18:28:11 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_img(t_game *game, int x, int y, void *img)
{
	mlx_put_image_to_window(game->mlx, game->win, img, (x  * 128), (y *128));
}

void	put_image(t_game *game, int x, int y)
{
	put_img(game, x, y, game->imgfloor);
	if (equal(game, x, y, '1'))
		put_img(game, x, y, game->imgwall);
	else if (equal(game, x, y, '0'))
		put_img(game, x, y, game->imgfloor);
	else if (equal(game, x, y, 'E'))
		put_img(game, x, y, game->imgexit);
	else if (equal(game, x, y, 'C'))
		put_img(game, x, y, game->imgcollect);
	else if (equal(game, x, y, 'P'))
		put_img(game, x, y, game->imgplayer);
	put_img(game, 0, 0, game->imgwall);
}

void	paint_map(t_game *game)
{
	int	x;
	int	y;
	
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			put_image(game, x, y);
			x++;
		}
		y++;
	}
}