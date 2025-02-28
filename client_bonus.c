/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 22:06:14 by machaouk          #+#    #+#             */
/*   Updated: 2025/02/17 23:20:14 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	bonus_handler(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message received\n");
}

void	send_bits(pid_t pid, unsigned char octet)
{
	int				i;
	unsigned char	bit;

	i = 8;
	while (i--)
	{
		bit = octet >> i & 1;
		if (bit == 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(0);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(0);
		}
		usleep(500);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		i = 0;
		if (signal(SIGUSR1, bonus_handler) == SIG_ERR || pid <= 0)
		{
			write(2, "Invalid pid, or signal Fail\n", 28);
			exit(0);
		}
		while (argv[2][i] != '\0')
		{
			send_bits(pid, (unsigned char)(argv[2][i]));
			i++;
		}
		send_bits(pid, '\0');
	}
	else
		ft_printf("Usage: [PID] [message]\n");
	return (0);
}
