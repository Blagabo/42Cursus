/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:42:15 by gblanco-          #+#    #+#             */
/*   Updated: 2024/11/07 18:27:19 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/utils.h"

int	is_duplicate(t_list *stack_a, int value)
{
	while (stack_a)
	{
		if (*(int *)(stack_a->content) == value)
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

void	check_valid_number(char *str, t_list *stack_a)
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

void	ft_free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

t_list	*parse_single_argument(char *arg, t_list *stack_a)
{
	char	**args;
	int		j;
	t_list	*new_node;
	int		*value;

	args = ft_split(arg, ' ');
	if (!args)
		error_exit("Error: Memory allocation failed");
	j = 0;
	while (args[j] != NULL)
	{
		check_valid_number(args[j], stack_a);
		value = malloc(sizeof(int));
		if (!value)
			error_exit("Error: Memory allocation failed");
		*value = ft_atoi(args[j]);
		new_node = ft_lstnew(value);
		ft_lstadd_back(&stack_a, new_node);
		j++;
	}
	ft_free_split(args);
	return (stack_a);
}

t_list	*parse_arguments(int argc, char **argv)
{
	t_list	*stack_a;
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
	return (stack_a);
}
