/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:29:52 by gblanco-          #+#    #+#             */
/*   Updated: 2024/11/11 18:32:49 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;

	if (!stack_b || !stack_b->top)
		return ;
	first = stack_b->top;
	stack_b->top = first->next;
	first->next = stack_a->top;
	stack_a->top = first;
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*first;

	if (!stack_a || !stack_a->top)
		return ;
	first = stack_a->top;
	stack_a->top = first->next;
	first->next = stack_b->top;
	stack_b->top = first;
}
