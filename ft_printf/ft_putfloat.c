/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 17:40:18 by wgolbert          #+#    #+#             */
/*   Updated: 2026/08/09 17:40:18 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_after_dot(double f, int precision)
{
	double	tmp;
	int		count;

	count = 0;
	tmp = f - (int)f;
	while (precision > 0)
	{
		tmp = tmp * 10;
		count += ft_putnbr((int)tmp);
		tmp = tmp - (int)tmp;
		precision--;
	}
	return (count);
}
int	ft_putfloat(double f, int precision)
{
	int	count;

	count = 0;
	if (f < 0)
	{
		count += ft_putchar('-');
		f = -f;
	}
	count += ft_putnbr((int)f);
	if (precision > 0)
	{
		count += ft_putchar('.');
		count += ft_after_dot(f, precision);
	}
	return (count);
}
