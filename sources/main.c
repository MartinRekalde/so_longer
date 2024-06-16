/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:39:05 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/16 21:39:49 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void parse_map(t_game *game, char *file)
{
    // (Your existing code to parse the map and set up the game structure)
    // Ensure to set game->player_x, game->player_y, game->collectibles, game->exit_x, game->exit_y

    // After parsing the map, check if the path is valid
    if (!is_valid_path(game))
    {
        ft_putendl_fd("Error\nInvalid map: No valid path to all collectibles and exit", 2);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
    {
        ft_putendl_fd("Usage: ./so_long <map_file>", 2);
        return (1);
    }
    parse_map(&game, argv[1]);

    // (Your existing code to start the game loop)
    return (0);
}
