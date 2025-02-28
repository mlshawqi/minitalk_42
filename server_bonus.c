/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 22:05:44 by machaouk          #+#    #+#             */
/*   Updated: 2025/02/17 23:10:03 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	print_byte(int *len, unsigned char *c)
{
	if (*len == 8)
	{
		*len = 0;
		if (*c == '\0')
		{
			*c = 0;
			return (1);
		}
		ft_printf("%c", *c);
		*c = 0;
	}
	return (0);
}

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				len;
	static pid_t			client_pid;
	unsigned char			bit;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	if (info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		len = 0;
	}
	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	c = (c << 1) | (bit & 1);
	len++;
	if (print_byte(&len, &c) == 1)
		if (kill(info->si_pid, SIGUSR1) == -1)
			exit (0);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("%d\n", getpid());
	while (1)
	{
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			exit(0);
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			exit(0);
	}
	return (0);
}
