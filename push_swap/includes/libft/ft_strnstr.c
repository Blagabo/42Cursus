/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:50:20 by gblanco-          #+#    #+#             */
/*   Updated: 2023/04/10 12:18:56 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *needlen, size_t len)
{
	size_t	i;
	size_t	j;

	if ((!hs || !needlen) && len == 0)
		return (0);
	i = 0;
	if (needlen[0] == '\0')
		return ((char *)hs);
	while (hs[i] != '\0' && i < len)
	{
		j = 0;
		while (hs[i + j] == needlen[j] && needlen[j] != '\0' && i + j < len)
			j++;
		if (needlen[j] == '\0')
			return ((char *)hs + i);
		i++;
	}
	return (0);
}
