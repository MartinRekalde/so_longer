/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrekalde <mrekalde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 16:25:45 by mrekalde          #+#    #+#             */
/*   Updated: 2024/06/21 17:23:25 by mrekalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_strchr(char const *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

char	*ft_strjoin(char *buffer, const char *content)
{
	size_t	buffer_len;
	size_t	content_len;
	char	*result;
	char	*result_ptr;
	char	*src;

	buffer_len = 0;
	if (!buffer && !content)
		return (NULL);
	if (buffer)
		buffer_len = ft_strlen(buffer);
	content_len = ft_strlen(content);
	result = (char *)malloc(sizeof(char) * (buffer_len + content_len + 1));
	if (!result)
		return (NULL);
	result_ptr = result;
	src = buffer;
	while (src && *src)
		*result_ptr++ = *src++;
	src = (char *)content;
	while (src && *src)
		*result_ptr++ = *src++;
	*result_ptr = '\0';
	free(buffer);
	return (result);
}
