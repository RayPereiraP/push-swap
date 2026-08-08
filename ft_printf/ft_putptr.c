/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 13:26:55 by wgolbert          #+#    #+#             */
/*   Updated: 2026/06/29 15:50:44 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	address;

	if (!ptr)
		return (ft_putstr("(nil)"));
	address = (unsigned long)ptr;
	return (ft_putstr("0x") + ft_puthexa(address, 0));
}
