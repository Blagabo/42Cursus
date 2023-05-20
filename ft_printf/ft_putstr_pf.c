/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:09:01 by gblanco-          #+#    #+#             */
/*   Updated: 2023/05/20 21:43:55 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	int	counter;

	if (!str)
		str = "(null)";
	counter = 0;
	while (*str)
	{
		counter += ft_putchar_pf(*str);
		str++;
	}
	return (counter);
}
