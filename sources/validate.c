/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:46:36 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/17 19:30:44 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	is_ber(char *argv)
{
	ft_strrchr(argv[1], '.');
	if (ft_strcmp(".ber", argv[1]) == 0)
		return (0);
	else
	{
		printf("Error, map file must be a .ber file.\n");
		exit (1);
	}
}

void	is_rectangle(t_game *game)
{
	int	x;
	int	y;

	x = ft_strlen(game->map[0]);
	y = 1;
	while (game->map[y])
	{
		if ((int)ft_strlen(game->map[y]) != x)
		{
			printf("Error, map is not rectangular.");
		}
		y++;
	}
}

