/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:36:39 by gblanco-          #+#    #+#             */
/*   Updated: 2024/11/07 19:00:57 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "./ft_printf/ft_printf.h"
# include "./libft/libft.h"
# include "./push_swap.h"

void	error_exit(char *msg);
int		ft_str_isdigit(const char *str);
void	print_stack(t_list *stack);
long	ft_atol(const char *str);

#endif