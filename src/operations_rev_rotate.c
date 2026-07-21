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

#include "push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->tail;
	stack->tail = tmp->next;
	stack->head->next = tmp;
	tmp->next = NULL;
	stack->head = tmp;
}

void	rra(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	ps->benchmark.rra++;
	write(1, "rra\n", 3);
}

void	rrb(t_push_swap *ps)
{
	reverse_rotate(ps->b);
	ps->benchmark.rrb++;
	write(1, "rrb\n", 3);
}

void	rrr(t_push_swap *ps)
{
	reverse_rotate(ps->a);
	reverse_rotate(ps->b);
	ps->benchmark.rrr++;
	write(1, "rrr\n", 3);
}