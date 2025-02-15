/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:10:48 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:10:48 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void	ft_format(const char **fr, va_list args, int *cnt);
int		ft_printf(const char *argument, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(long n, int *len);
void	ft_putstr(char *str, int *len);

#endif