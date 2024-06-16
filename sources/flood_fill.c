/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:13:13 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/16 21:38:26 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void flood_fill(t_game *game, int x, int y, char target)
{
    // Check boundaries and if the current cell is not the target character
    if (x < 0 || x >= game->map_height || y < 0 || y >= game->map_width || game->map[x][y] != target)
        return;

    // Mark the current cell as visited by changing its value
    game->map[x][y] = 'V';

    // Recursively visit all adjacent cells
    flood_fill(game, x + 1, y, target);
    flood_fill(game, x - 1, y, target);
    flood_fill(game, x, y + 1, target);
    flood_fill(game, x, y - 1, target);
}

// Function to check if there's a valid path to all collectibles and exit
int is_valid_path(t_game *game)
{
    // Perform flood fill from the player's starting position
    flood_fill(game, game->player_x, game->player_y, '0');

    // Check if all collectibles and exit are reachable
    for (int i = 0; i < game->map_height; i++)
    {
        for (int j = 0; j < game->map_width; j++)
        {
            if ((game->map[i][j] == 'C' || game->map[i][j] == 'E') && game->map[i][j] != 'V')
                return 0; // If any collectible or exit is not visited, return false
        }
    }
    return 1;
}
