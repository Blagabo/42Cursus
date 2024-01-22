/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:46:48 by gblanco-          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:55 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunint_pf(unsigned int n)
{
	int	counter;

	counter = 0;
	if (n <= 9)
		counter += ft_putchar_pf(48 + n);
	else
	{
		counter += ft_putunint_pf(n / 10);
		counter += ft_putchar_pf(48 + (n % 10));
	}
	return (counter);
}
