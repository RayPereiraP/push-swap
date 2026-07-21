/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:05:51 by rayperei          #+#    #+#             */
/*   Updated: 2026/06/28 21:05:52 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_stack *a, t_stack *b) //para lidar com erros de parsing, libera memoria 
{
	free_stack(a);
	free_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}