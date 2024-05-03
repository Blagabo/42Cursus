/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 08:56:53 by gblanco-          #+#    #+#             */
/*   Updated: 2024/05/03 11:48:39 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		++i;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	k;
	size_t	i;
	char	*result;

	if (!s1 && !s2)
		return (NULL);
	result = malloc(sizeof(char) * (ft_strlen(s1)) + (ft_strlen(s2) + 1));
	if (!result)
		return (NULL);
	i = 0;
	k = 0;
	while (s1 && s1[i])
		result[k++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		result[k++] = s2[i++];
	result[k] = '\0';
	free((char *)s1);
	return (result);
}

void	ft_bzero(void *s, unsigned int n)
{
	char			*dst;
	unsigned int	x;

	dst = s;
	x = 0;
	while (x < n)
	{
		dst[x] = '\0';
		++x;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count > 0 && size > 0 && count > ULONG_MAX / size)
		return (NULL);
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
