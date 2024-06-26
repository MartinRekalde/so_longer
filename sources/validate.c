/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:46:36 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 17:20:27 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_ber(char *argv)
{
	int	i;

	i = ft_strlen(argv);
	i = i - 4;
	if (i > 1 && (argv[i] == '.' && argv[i + 1] == 'b'
			&& argv[i + 2] == 'e' && argv[i + 3] == 'r' && argv[i - 1] != '/'))
		return ;
	else
	{
		write(1, "Error, map file must be a .ber file.\n", 38);
		exit(1);
	}
}

void	is_rectangle(t_game *game)
{
	size_t	x;
	int		y;

	x = ft_strlen(game->map[0]);
	y = 0;
	while (game->map[y + 1])
	{
		if (ft_strlen(game->map[y]) != x)
			break ;
		y++;
	}
	if (game->map[y][ft_strlen(game->map[y]) - 1] == '\n')
	{
		if (ft_strlen(game->map[y]) != x)
			map_error(game, "Error, is not rectangle.\n", 1);
	}
	else
	{
		if (ft_strlen(game->map[y]) + 1 != x)
			map_error(game, "Error, is not rectangle.\n", 1);
	}
}
