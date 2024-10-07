/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:26:11 by gblanco-          #+#    #+#             */
/*   Updated: 2023/11/28 12:28:36 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	ft_printf("Entero: %d\n", 42);
	ft_printf("Cadena: %s\n", "Hola, mundo!");
	ft_printf("Carácter: %c\n", 'A');
	ft_printf("Puntero: %p\n", &main);
	ft_printf("Hexadecimal: %x\n", 255);
	ft_printf("Hexadecimal: %X\n", 255);
	ft_printf("Número sin signo: %u\n", 12345);
	ft_printf("Número decimal: %d\n", -42);
	return (0);
}
