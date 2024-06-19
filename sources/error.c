/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:44:57 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/19 20:45:00 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	buffer_error(char *message, int fd, char *buffer)
{
	free(buffer);
	close(fd);
	printf("%s\n", message);
	exit(1);
}

void	EP_error(char *message)
{
	printf("%s\n", message);
	exit(1);
}

void	free_split(t_game *game)
{
	int x;

	x = 0;
	if (game)
	{
		if (game->map)
		{
			while (game->map[x])
			{
				free(game->map[x]);
				//free(game->map_copy[x]);
				x++;
			}
			free(game->map);
			free(game->map_copy);
		}
	}
	if (game->mlx)
		free(game->mlx);
}	

void	free_map(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_split(game);
		if (game->mlx)
			free(game->mlx);
	}
}
void	map_error(t_game *game, char *message, int error)
{
	if (error != 1)
		destroy_mlx(game);
	//free_map(game);
	printf("%s\n", message);
	exit(0);
}
