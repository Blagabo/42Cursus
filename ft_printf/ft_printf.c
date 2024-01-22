/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 15:49:00 by gblanco-          #+#    #+#             */
/*   Updated: 2023/11/28 12:56:02 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char *format, va_list args)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += ft_putchar_pf(va_arg(args, int));
	else if (*format == 's')
		i += ft_putstr_pf(va_arg(args, char *));
	else if (*format == 'p')
		i += ft_putptr_pf(va_arg(args, unsigned long long));
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr_pf(va_arg(args, int));
	else if (*format == 'u')
		i += ft_putunint_pf(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X')
		i += ft_puthexa_pf(va_arg(args, unsigned int), *format);
	else if (*format == '%')
		i += ft_putchar_pf(*format);
	else
		return (0);
	return (i);
}

int	ft_printf(char const *format, ...)
{
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			i += ft_format((char *)format, args);
		}
		else
			i += ft_putchar_pf(*format);
		++format;
	}
	va_end(args);
	return (i);
}
