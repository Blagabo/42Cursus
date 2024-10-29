/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:15:29 by gblanco-          #+#    #+#             */
/*   Updated: 2023/04/10 12:13:58 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		number = -number;
		count++;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		digs;
	int		i;

	digs = count_digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	num = ft_calloc(digs + 1, sizeof(char));
	if (!num)
		return (0);
	if (n < 0)
	{
		n = -n;
		num[0] = '-';
	}
	i = digs - 1;
	while (n >= 0 && n != 0)
	{
		num[i] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (num);
}
