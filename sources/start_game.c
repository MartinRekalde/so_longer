/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:17:58 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/17 21:32:56 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (int)game->map_x * 64, (int)game->map_y * 64, "So Long !");
	get_xpm(game);
	paint_map(game);
	//ARREGLAR hook(game);
	mlx_loop(game->mlx);
}