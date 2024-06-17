/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:10:23 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/17 20:48:21 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	destroy_mlx(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
}

int	close_window(t_game *game)
{
	map_error(game, "Window closed", 0);
	return (0);
}

void	ft_hook(t_game *game)
{
	mlx_hook(game->win, 17, 1, close_window, game);
	mlx_hook(game->win, 2, 1, key_press, game);
}