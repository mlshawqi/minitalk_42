/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: machaouk <marvin@42.fr>                    #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 22:07:23 by machaouk          #+#    #+#             */
/*   Updated: 2025-02-17 22:07:23 by machaouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *argument, ...)
{
	va_list	arg;
	int		count;

	va_start(arg, argument);
	count = 0;
	while (*argument)
	{
		if (*argument == '%')
		{
			ft_format(&argument, arg, &count);
			if (count == -1)
				return (-1);
		}
		else
			ft_putchar(*argument, &count);
		argument++;
	}
	return (count);
}
