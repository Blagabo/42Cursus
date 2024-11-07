/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:19:32 by gblanco-          #+#    #+#             */
/*   Updated: 2023/03/24 17:27:44 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*result;

	if (!str)
		return (NULL);
	if (start + len >= ft_strlen(str))
		len = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		return (ft_strdup(""));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, str + start, len + 1);
	result[len] = '\0';
	return (result);
}
