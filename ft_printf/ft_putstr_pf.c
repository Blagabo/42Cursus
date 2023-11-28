/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:09:01 by gblanco-          #+#    #+#             */
/*   Updated: 2023/11/28 13:00:57 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str)
{
	int	counter;
	int	temp;

	if (!str)
		str = "(null)";
	counter = 0;
	while (*str)
	{
		temp = ft_putchar_pf(*str);
		if (temp == -1)
			return (-1);
		counter += temp;
		str++;
	}
	return (counter);
}
