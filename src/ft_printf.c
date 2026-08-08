/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:29:50 by rayperei          #+#    #+#             */
/*   Updated: 2026/08/08 19:29:56 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdarg.h>
#include <stdio.h>

static void	handle_specifier(char c, va_list args, int fd)
{
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), fd);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), fd);
	else if (c == 'u')
		ft_putunbr_fd(va_arg(args, unsigned int), fd);
	else if (c == 'f')
		ft_putdouble_fd(va_arg(args, double), fd);
	else if (c == 'c')
		ft_putchar_fd((char)va_arg(args, int), fd);
	else if (c == '%')
		ft_putchar_fd('%', fd);
}

void	ft_printf(FILE *stream, const char *fmt, ...)
{
	va_list	args;
	int		fd;
	int		i;

	fd = fileno(stream);
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			handle_specifier(fmt[i], args, fd);
		}
		else
			ft_putchar_fd(fmt[i], fd);
		i++;
	}
	va_end(args);
}
