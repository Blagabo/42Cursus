/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:08:25 by gblanco-          #+#    #+#             */
/*   Updated: 2023/05/20 21:33:15 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_ptr(unsigned long long hexa)
{
	int	i;

	i = 0;
	if (hexa >= 16)
	{
		i += ft_puthexa_ptr(hexa / 16);
		i += ft_puthexa_ptr(hexa % 16);
	}
	else
	{
		if (hexa <= 9)
			i += ft_putchar_pf((hexa + 48));
		else
			i += ft_putchar_pf(hexa - 10 + 'a');
	}
	return (i);
}

int	ft_putptr_pf(unsigned long long ptr)
{
	int	i;

	i = 0;
	i += ft_putstr_pf("0x");
	i += ft_puthexa_ptr(ptr);
	return (i);
}
