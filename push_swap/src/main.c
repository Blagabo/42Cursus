/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:30:55 by gblanco-          #+#    #+#             */
/*   Updated: 2024/11/11 17:33:24 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	stack_a = parse_arguments(argc, argv);
	ft_printf("Original: ");
	print_stack(stack_a->top);
	sa(stack_a);
	ft_printf("Después del sa: ");
	print_stack(stack_a->top);
	return (0);
}
