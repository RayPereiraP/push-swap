/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:15:21 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/20 11:15:21 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*algo_adaptive(t_stack *stack)
{
	int	sorted_tail;
	int	sorted_head;

	sorted_head = 0;
	sorted_tail = stack->size_a - 1;
	while (sorted_head < sorted_tail)
	{
		process_a(stack, sorted_tail);
		process_b(stack, sorted_head);
		sorted_head++;
		sorted_tail--;
	}
	restore_stack(stack);
}

static void	process_a(t_stack *stack, int sorted)
{
	int	i;

	i = 0;
	while (i < sorted)
	{
		if (stack->a->value > stack->a->next->value)
			sa(stack);
		pb(stack);
		i++;
	}
}
static void	process_b(t_stack *stack, int sorted)
{
	while (sorted < stack->size_b)
	{
		if (stack->b->value < stack->b->next->value)
			sb(stack);
		pa(stack);
	}
}

static void	restore_stack(t_stack *stack)
{
	while (stack->size_b > 0)
		pa(stack);
}