/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:38:18 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/20 21:37:28 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	xpm_check(t_game *game)
{
	if (!game->imgplayer || !game->imgwall || !game->imgfloor || !game->imgexit || !game->collect)
		map_error(game, "Error, one or more textures missing.", 0);
}

void	get_xpm(t_game *game)
{
	int	x;
	int	y;

	x = 128;
	y = 128;
	game->imgplayer = mlx_xpm_file_to_image(game->mlx, AVATAR, &(x) , &(y));
	game->imgwall = mlx_xpm_file_to_image(game->mlx, WALL, &(x), &(y));
	game->imgfloor = mlx_xpm_file_to_image(game->mlx, FLOOR, &(x), &(y));
	game->imgexit = mlx_xpm_file_to_image(game->mlx, EXIT, &(x), &(y));
	game->imgcollect = mlx_xpm_file_to_image(game->mlx, COLLECT, &(x), &(y));
	game->imgfloor = mlx_xpm_file_to_image(game->mlx, FLOOR, &(x), &(y));
	xpm_check(game);
}
