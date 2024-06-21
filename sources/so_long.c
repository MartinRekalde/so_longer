/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:39:05 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 16:16:11 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_s_game(t_game *game)
{
	game->map = NULL;
	game->map_copy = NULL;
	game->mlx = NULL;
	game->map_x = 0;
	game->map_y = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->collect = 0;
	game->exit_x = 0;
	game->exit_y = 0;
	game->moves = 0;
	game->count = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (printf("\nUsage: ./so_long map.ber\n"), 1);
	else
	{
		is_ber(argv[1]);
		init_s_game(&game);
		game.map = read_map(argv[1]);
		game.map_copy = read_map(argv[1]);
		is_rectangle(&game);
		player_position(game.map, &game);
		exit_position(game.map, &game);
		get_map_xy(&game);
		check_map(&game);
		finishable_map(&game);
		start_game(&game);
	}
	return (0);
}
