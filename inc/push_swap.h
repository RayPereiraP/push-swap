/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:04 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 17:22:59 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void rotate_to_min(t_stack *stack, int min_idx)
{
	if (min_idx <= stack->size_a / 2)
	{
		while (min_idx-- > 0)
			ra(stack);
	}
	else
	{
		while (min_idx++ < stack->size_a)
			rra(stack);
	}
}
void algo_simple(t_stack *stack)
{
	

	while (stack->size_a > 0)
	{
		rotate_to_min(stack, get_min_index(stack));
		pb(stack);
	}

	while (stack->size_b > 0)
	pa(stack);
}
