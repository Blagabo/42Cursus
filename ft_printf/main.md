/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:14:07 by gblanco-          #+#    #+#             */
/*   Updated: 2023/05/21 01:10:26 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main(void)
{
	int		minusOne;
	int		one;
	int		fifteen;
	int		sixteen;
	int		seventeen;
	long	minLong;
	long	maxLong;
	int		minInt;
	int		maxInt;
	int		zero;

	minusOne = -1;
	one = 1;
	fifteen = 15;
	sixteen = 16;
	seventeen = 17;
	minLong = LONG_MIN;
	maxLong = LONG_MAX;
	minInt = INT_MIN;
	maxInt = INT_MAX;
	zero = 0;
	ft_printf(" %p \n", (void *)&minusOne);
	ft_printf(" %p \n", (void *)&one);
	ft_printf(" %p \n", (void *)&fifteen);
	ft_printf(" %p \n", (void *)&sixteen);
	ft_printf(" %p \n", (void *)&seventeen);
	ft_printf(" %p %p \n", (void *)&minLong, (void *)&maxLong);
	ft_printf(" %p %p \n", (void *)&minInt, (void *)&maxInt);
	ft_printf(" %p %p \n", (void *)&zero, (void *)&zero);
	printf("ORIGINAL: \n");
	printf(" %p \n", (void *)&minusOne);
	printf(" %p \n", (void *)&one);
	printf(" %p \n", (void *)&fifteen);
	printf(" %p \n", (void *)&sixteen);
	printf(" %p \n", (void *)&seventeen);
	printf(" %p %p \n", (void *)&minLong, (void *)&maxLong);
	printf(" %p %p \n", (void *)&minInt, (void *)&maxInt);
	printf(" %p %p \n", (void *)&zero, (void *)&zero);
	return (0);
}
