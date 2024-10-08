/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:46:54 by gblanco-          #+#    #+#             */
/*   Updated: 2024/10/08 11:49:58 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%d\n", received);
		exit(0);
	}
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (c >> i & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				exit(1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				exit(1);
			}
		}
		usleep(100);
	}
}

static void	mt_kill(int pid, char *str)
{
	while (*str)
		send_char(pid, *str++);
	send_char(pid, 0);
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	ft_printf("Sent: %d\n", ft_strlen(argv[2]));
	ft_printf("Received: ");
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
