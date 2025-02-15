/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-10 10:10:19 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-10 10:10:19 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(const char **fr, va_list args, int *cnt)
{
	(*fr)++;
	if (!**fr)
		*cnt = -1;
	else if (**fr == 'd' || **fr == 'i')
		ft_putnbr(va_arg(args, int), cnt);
	else if (**fr == 's')
		ft_putstr(va_arg(args, char *), cnt);
	else if (**fr == 'c')
		ft_putchar((char)va_arg(args, int), cnt);
	else if (**fr == '%')
		ft_putchar('%', cnt);
	else
		ft_putchar(**fr, cnt);
}
