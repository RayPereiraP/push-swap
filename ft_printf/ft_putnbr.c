/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:17:28 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/03 13:30:41 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digit(long n)
{
	int	count;

	count = 0;
	if (n <= 0)
	{
		n *= -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(long n)
{
	int		count;
	long	temp;
	char	*str;

	count = ft_count_digit(n);
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[count] = '\0';
	temp = n;
	if (n < 0)
	{
		str[0] = '-';
		temp *= -1;
	}
	while (temp > 0)
	{
		count--;
		str[count] = (temp % 10) + '0';
		temp = temp / 10;
	}
	return (str);
}

int	ft_putnbr(long n)
{
	char	*str;
	int		count;

	if (n == 0)
		return (ft_putchar('0'));
	str = ft_itoa(n);
	count = ft_putstr (str);
	free(str);
	return (count);
}
