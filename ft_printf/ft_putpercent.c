/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpercent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 22:12:33 by wgolbert          #+#    #+#             */
/*   Updated: 2026/08/09 22:12:33 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpercent(double n)
{
	int	percent;
	int	count;

	count = 0;
	percent = n * 10000;
	count += ft_putnbr(percent / 100);
	count += ft_putchar('.');
	if (percent % 100 < 10)
		count += ft_putchar('0');
	count += ft_putnbr(percent % 100);
	count += ft_putchar('%');
	return (count);
}
