/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:54:59 by gblanco-          #+#    #+#             */
/*   Updated: 2024/10/01 12:09:24 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	bit_pos = 0;
static char	character = 0;

void	signal_handler(int signum)
{
	if (signum == SIGUSR2)
		character |= (1 << (7 - bit_pos));
	bit_pos++;
	if (bit_pos == 8)
	{
		ft_printf("Character received: %c\n", character);
		bit_pos = 0;
		character = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server ON PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
