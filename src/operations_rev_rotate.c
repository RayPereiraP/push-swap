/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:51:07 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/18 11:51:07 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_list	*last;
	t_list	*prev;

	if (stack->size <= 1)
		return ;
	prev = stack->head;
	while (prev->next != stack->tail)
		prev = prev->next;
	last = stack->tail;
	prev->next = NULL;
	stack->tail = prev;
	last->next = stack->head;
	stack->head = last;
}

void	rra(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	ps->benchmark.rra++;
	if (ps->flags.bench == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_push_swap *ps)
{
	reverse_rotate(ps->b);
	ps->benchmark.rrb++;
	if (ps->flags.bench == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	ps->benchmark.rrr++;
	if (ps->flags.bench == 0)
		write(1, "rrr\n", 4);
}
