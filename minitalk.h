/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 22:05:49 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-17 22:05:49 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

int		print_byte(int *len, unsigned char *c);
void	signal_handler(int sig, siginfo_t *info, void *context);
void	send_bits(pid_t pid, unsigned char octet);

#endif