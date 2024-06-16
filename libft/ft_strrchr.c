/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 16:39:01 by mrekalde          #+#    #+#             */
/*   Updated: 2023/10/11 11:13:57 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = ((char *) s);
	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{	
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}

/*
int	main()
{
	char 	str[] = "esto es super increible";
	char	a = 'i';
	char	*b;

	b = ft_strrchr(str, a);
	if (b != NULL)
		printf("ft_		%s\n", b);
	else
		printf("ft_		NULL");
	printf("original	%s", strrchr(str, a));
}
*/
