/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:16:19 by gblanco-          #+#    #+#             */
/*   Updated: 2023/03/15 18:56:08 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	di;
	size_t	si;

	si = ft_strlen(src);
	if (!dst && size == 0)
		return (si);
	j = ft_strlen(dst);
	di = j;
	if (size <= di)
		return (size + si);
	i = 0;
	while (src[i] && j + 1 < size)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (di + si);
}
