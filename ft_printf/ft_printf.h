/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 12:57:02 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/03 13:29:56 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putnbr(long n);
int	ft_puthexa(unsigned long n, int upper);
int	ft_putstr(char *str);
int	ft_putptr(void *ptr);
int	ft_putchar(char c);
int	ft_putfloat(double f, int precision);
int	ft_putpercent(double n);
int	ft_printf(const char *s, ...);

#endif