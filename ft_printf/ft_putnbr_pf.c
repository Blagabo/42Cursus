/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:43:53 by gblanco-          #+#    #+#             */
/*   Updated: 2023/11/28 13:01:04 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pf(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		n = -n;
		i += write(1, "-", 1);
		i += write(1, "2", 1);
		i += ft_putnbr_pf(147483648);
	}
	else if (n < 0)
	{
		n = -n;
		i += write(1, "-", 1);
		i += ft_putnbr_pf(n);
	}
	else if (n >= 0 && n <= 9)
		i += ft_putchar_pf(48 + n);
	else
	{
		i += ft_putnbr_pf(n / 10);
		i += ft_putchar_pf(48 + (n % 10));
	}
	return (i);
}
