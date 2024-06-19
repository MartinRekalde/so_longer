/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:17:58 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/19 21:55:54 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->map_x -1) * 16, (game->map_y) * 16, "So Long !");
	get_xpm(game);
	paint_map(game);
	hook(game);
	mlx_loop(game->mlx);
}
