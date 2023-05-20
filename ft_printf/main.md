/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:14:07 by gblanco-          #+#    #+#             */
/*   Updated: 2023/05/20 21:39:23 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int	i;

	i = 0;
	i += ft_printf("Esto es lo que queremos imprimir: %u\n");
	ft_printf("Cantidad de caracteres: %d\n", i);
	printf("Esto es lo que queremos imprimir: %u\n");
	return (0);
}
