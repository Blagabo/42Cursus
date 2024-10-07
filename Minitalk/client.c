/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:46:54 by gblanco-          #+#    #+#             */
/*   Updated: 2024/10/01 12:09:25 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit(pid_t server_pid, char c, int i)
{
	if (i < 0)
		return ;
	if ((c >> i) & 1)
		kill(server_pid, SIGUSR2);
	else
		kill(server_pid, SIGUSR1);
	usleep(100);
	send_bit(server_pid, c, i - 1);
}

void	send_char(pid_t server_pid, char c)
{
	send_bit(server_pid, c, 7);
}

void	send_string(pid_t server_pid, char *str)
{
	if (*str == '\0')
		return ;
	send_char(server_pid, *str);
	send_string(server_pid, str + 1);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		printf("Usage: %s <PID> <signal>\n", argv[0]);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	send_string(server_pid, argv[2]);
	return (0);
}
