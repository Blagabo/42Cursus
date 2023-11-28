/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:08:25 by gblanco-          #+#    #+#             */
/*   Updated: 2023/11/28 13:01:01 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_ptr(unsigned long long ptr)
{
	int	len;

	if (ptr == 0)
		return (1);
	len = 0;
	while (ptr != 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

int	ft_puthexa_ptr(unsigned long long hexa)
{
	int	count;

	count = 0;
	if (hexa >= 16)
	{
		count += ft_puthexa_ptr(hexa / 16);
		count += ft_puthexa_ptr(hexa % 16);
	}
	else
	{
		if (hexa <= 9)
			count += ft_putchar_pf((hexa + '0'));
		else
			count += ft_putchar_pf((hexa - 10 + 'a'));
	}
	return (count);
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	char_printed;

	char_printed = 0;
	char_printed += write(1, "0x", 2);
	if (ptr == 0)
		char_printed += write(1, "0", 1);
	else
	{
		ft_puthexa_ptr(ptr);
		char_printed += len_ptr(ptr);
	}
	return (char_printed);
}
