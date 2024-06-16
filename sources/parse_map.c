/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:50:57 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/16 21:50:58 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Helper function to read the map file into a string
static char *read_map_file(char *file)
{
    int     fd;
    char    *line;
    char    *map_content;
    char    *temp;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror("Error\nUnable to open map file");
        exit(EXIT_FAILURE);
    }
    map_content = ft_strdup("");
    while ((line = get_next_line(fd)))
    {
        temp = map_content;
        map_content = ft_strjoin(map_content, line);
        free(temp);
        free(line);
    }
    close(fd);
    return (map_content);
}

// Helper function to split the map string into a 2D array
static char **split_map(char *map_content)
{
    char **map;

    map = ft_split(map_content, '\n');
    if (!map)
    {
        perror("Error\nFailed to split map content");
        exit(EXIT_FAILURE);
    }
    return (map);
}

// Helper function to initialize the game structure
static void init_game_structure(t_game *game)
{
    game->map = NULL;
    game->map_width = 0;
    game->map_height = 0;
    game->player_x = -1;
    game->player_y = -1;
    game->collectibles = 0;
    game->exit_x = -1;
    game->exit_y = -1;
    game->moves = 0;
}

// Helper function to validate the map's characters and dimensions
static void validate_map_characters(t_game *game)
{
    int i, j;

    for (i = 0; i < game->map_height; i++)
    {
        for (j = 0; j < game->map_width; j++)
        {
            char cell = game->map[i][j];
            if (cell == 'P')
            {
                if (game->player_x != -1 || game->player_y != -1)
                    error_exit("Error\nInvalid map: Multiple starting positions");
                game->player_x = i;
                game->player_y = j;
            }
            else if (cell == 'C')
                game->collectibles++;
            else if (cell == 'E')
            {
                if (game->exit_x != -1 || game->exit_y != -1)
                    error_exit("Error\nInvalid map: Multiple exits");
                game->exit_x = i;
                game->exit_y = j;
            }
            else if (cell != '0' && cell != '1')
                error_exit("Error\nInvalid map: Invalid character found");
        }
    }
    if (game->player_x == -1 || game->player_y == -1)
        error_exit("Error\nInvalid map: No starting position");
    if (game->collectibles == 0)
        error_exit("Error\nInvalid map: No collectibles");
    if (game->exit_x == -1 || game->exit_y == -1)
        error_exit("Error\nInvalid map: No exit");
}

// Helper function to check if the map is rectangular and surrounded by walls
static void validate_map_shape(t_game *game)
{
    int i, width;

    game->map_height = 0;
    while (game->map[game->map_height])
        game->map_height++;
    width = ft_strlen(game->map[0]);
    game->map_width = width;
    for (i = 1; i < game->map_height; i++)
    {
        if (ft_strlen(game->map[i]) != width)
            error_exit("Error\nInvalid map: Non-rectangular map");
    }
    for (i = 0; i < game->map_height; i++)
    {
        if (game->map[i][0] != '1' || game->map[i][width - 1] != '1')
            error_exit("Error\nInvalid map: Map not surrounded by walls");
    }
    for (i = 0; i < width; i++)
    {
        if (game->map[0][i] != '1' || game->map[game->map_height - 1][i] != '1')
            error_exit("Error\nInvalid map: Map not surrounded by walls");
    }
}

void parse_map(t_game *game, char *file)
{
    char *map_content;

    init_game_structure(game);
    map_content = read_map_file(file);
    game->map = split_map(map_content);
    free(map_content);
    validate_map_shape(game);
    validate_map_characters(game);
    if (!is_valid_path(game))
        error_exit("Error\nInvalid map: No valid path to all collectibles and exit");
}
