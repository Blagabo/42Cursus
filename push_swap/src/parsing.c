/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:42:15 by gblanco-          #+#    #+#             */
/*   Updated: 2024/11/11 17:48:44 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"

int	is_duplicate(t_node *stack_a, int value)
{
	while (stack_a)
	{
		if (stack_a->value == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	check_valid_number(char *str, t_node *stack_a)
{
	long	value;

	value = ft_atol(str);
	if (value < INT_MIN || value > INT_MAX)
		error_exit("Error: Number out of int range");
	if (ft_str_isdigit(str) == 0)
		error_exit("Error: Invalid number");
	if (is_duplicate(stack_a, (int)value))
		error_exit("Error: Duplicate number");
}

void	parse_value(char *arg, t_node **stack_a)
{
	int		value;
	t_node	*new_node;

	check_valid_number(arg, *stack_a);
	value = ft_atoi(arg);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
		error_exit("Error: Memory allocation failed");
	new_node->value = value;
	new_node->next = NULL;
	ft_lstadd_back((t_list **)stack_a, (t_list *)new_node);
}

t_node	*parse_single_argument(char *arg, t_node *stack_a)
{
	char	**args;
	int		j;

	args = ft_split(arg, ' ');
	if (!args)
		error_exit("Error: Memory allocation failed");
	j = 0;
	while (args[j] != NULL)
	{
		parse_value(args[j], &stack_a);
		j++;
	}
	ft_free_split(args);
	return (stack_a);
}

t_stack	*parse_arguments(int argc, char **argv)
{
	t_node	*stack_a;
	t_stack	*parsed_stack;
	int		i;

	stack_a = NULL;
	if (argc < 2)
		error_exit("Error: No arguments provided");
	i = 1;
	while (i < argc)
	{
		stack_a = parse_single_argument(argv[i], stack_a);
		i++;
	}
	parsed_stack = malloc(sizeof(t_stack));
	if (!parsed_stack)
		error_exit("Error: Memory allocation failed");
	parsed_stack->top = stack_a;
	return (parsed_stack);
}
