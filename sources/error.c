/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:44:57 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 16:43:07 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_printf(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	write(1, "\n", 2);
}

void	ep_error(char *message)
{
	ft_printf(message);
	exit(1);
}

void	free_by_char(t_game *game)
{
	int	x;

	x = 0;
	if (game)
	{
		if (game->map)
		{
			while (game->map[x])
			{
				free(game->map[x]);
				free(game->map_copy[x]);
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
			free_by_char(game);
	}
}

void	map_error(t_game *game, char *message, int error)
{
	if (error != 1)
		destroy_mlx(game);
	free_map(game);
	ft_printf(message);
	exit(0);
}
