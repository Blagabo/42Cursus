/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:56:57 by gblanco-          #+#    #+#             */
/*   Updated: 2023/05/20 21:43:44 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa_pf(unsigned int hexa, char form)
{
	int	i;

	i = 0;
	if (hexa >= 16)
	{
		i += ft_puthexa_pf(hexa / 16, form);
		i += ft_puthexa_pf(hexa % 16, form);
	}
	else
	{
		if (hexa <= 9)
			i += ft_putchar_pf((hexa + 48));
		else
		{
			if (form == 'x')
				i += ft_putchar_pf(hexa - 10 + 97);
			if (form == 'X')
				i += ft_putchar_pf(hexa - 10 + 65);
		}
	}
	return (i);
}
