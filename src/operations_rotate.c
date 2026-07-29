/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operarions_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:50:37 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/18 11:50:37 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head;
	stack->head = tmp->next;
	stack->tail->next = tmp;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	ra(t_push_swap *ps)
{
	rotate(ps->a);
	ps->benchmark.ra++;
	if (ps->flags.bench == 0)
		write(1, "ra\n", 3);
}

void	rb(t_push_swap *ps)
{
	rotate(ps->b);
	ps->benchmark.rb++;
	if (ps->flags.bench == 0)
		write(1, "rb\n", 3);
}

void	rr(t_push_swap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
	ps->benchmark.rr++;
	if (ps->flags.bench == 0)
		write(1, "rr\n", 3);
}
