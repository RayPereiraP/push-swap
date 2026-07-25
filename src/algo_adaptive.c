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

static void	process_a(t_push_swap *ps, int sorted)
{
	int	i;

	i = 0;
	while (i < sorted)
	{
		if (ps->a->head->value > ps->a->head->next->value)
			sa(ps);
		pb(ps);
		i++;
	}
}

static void	process_b(t_push_swap *ps, int sorted)
{
	while (sorted < ps->b->size)
	{
		if (ps->b->head->value < ps->b->head->next->value)
			sb(ps);
		pa(ps);
	}
}

static void	restore_stack(t_push_swap *ps)
{
	while (ps->b->size > 0)
		pa(ps);
}
void	algo_adaptive(t_push_swap *ps)
{
	int	sorted_tail;
	int	sorted_head;

	sorted_head = 0;
	sorted_tail = ps->a->size - 1;
	while (sorted_head < sorted_tail)
	{
		process_a(ps, sorted_tail);
		process_b(ps, sorted_head);
		sorted_head++;
		sorted_tail--;
	}
	restore_stack(ps);
}
