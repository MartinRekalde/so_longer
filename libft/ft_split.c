/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:08:52 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/18 17:33:28 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s, char c)
{
	int	i;
	int	num_words;

	i = 0;
	num_words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		num_words++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] == c)
			i++;
	}
	return (num_words);
}

void	ft_clean(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
}

int	fill_words(char **array, char const *s, char c)
{
	int	start;
	int	end;
	int	word_index;

	end = 0;
	word_index = 0;
	while (word_index < ft_countword(s, c))
	{
		start = end;
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		array[word_index] = ft_substr(s, start, end - start);
		if (!array[word_index])
		{
			ft_clean(array);
			return (0);
		}
		++word_index;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**array;

	num_words = ft_countword(s, c);
	array = malloc(sizeof(char *) * (num_words + 1));
	if (!array)
		return (NULL);
	array[num_words] = NULL;
	if (!fill_words(array, s, c))
		return (NULL);
	return (array);
}
/*
int main() {
    char input_string[] = "Hello,World,This,is,a,test";
    char delimiter = ',';
    char **result = ft_split(input_string, delimiter);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Word %d: %s\n", i + 1, result[i]);
        }
        ft_clean(result);
    } else {
        printf("Error al dividir la cadena.\n");
    }

    return 0;
}
*/