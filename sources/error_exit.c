/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 21:50:45 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/16 21:50:50 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// Error handling function to print message and exit
void error_exit(char *message)
{
    ft_putendl_fd(message, 2);
    exit(EXIT_FAILURE);
}
