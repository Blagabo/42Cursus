/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gblanco- <gblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 19:54:59 by gblanco-          #+#    #+#             */
/*   Updated: 2024/10/10 00:07:13 by gblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bin_to_char(int sig, char *c)
{
	if (sig == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (sig == SIGUSR2)
		*c <<= 1;
}

void	ft_sig_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t	client_pid;
	static char		c;
	static int		i;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	ft_bin_to_char(signum, &c);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
			return ;
		}
		ft_printf("%c", c);
		c = 0;
	}
	kill(client_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("My Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = ft_sig_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Error sigaction\n", 1);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Error sigaction\n", 1);
	while (1)
		pause();
	return (0);
}
