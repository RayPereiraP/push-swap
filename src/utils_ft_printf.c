/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_printf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 19:28:30 by rayperei          #+#    #+#             */
/*   Updated: 2026/08/08 19:28:40 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		s = "(null)";
	while (*s)
		ft_putchar_fd(*s++, fd);
}

void	ft_putnbr_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putunbr_fd(unsigned long n, int fd)
{
	if (n >= 10)
		ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_putdouble_fd(double n, int fd)
{
	long	int_part;
	double	frac;
	int		i;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	int_part = (long)n;
	frac = n - int_part;
	ft_putnbr_fd(int_part, fd);
	ft_putchar_fd('.', fd);
	i = 0;
	while (i++ < 2)
	{
		frac *= 10;
		ft_putchar_fd((int)frac % 10 + '0', fd);
	}
}
