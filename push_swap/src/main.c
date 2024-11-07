/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:30:55 by gblanco-          #+#    #+#             */
/*   Updated: 2024/11/07 17:50:54 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;

	stack_a = parse_arguments(argc, argv);
	print_stack(stack_a);
	return (0);
}
