/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:51:13 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/18 11:51:13 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack *stack)
{
	t_list	*tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->head->next;
	stack->head->next = tmp->next;
	tmp->next = stack->head;
	stack->head = tmp;
	if (stack->size == 2)
		stack->tail = stack->head->next;
}

void	sa(t_push_swap *ps)
{
	swap(ps->a);
	ps->benchmark.sa++;
	if (ps->flags.bench == 0)
		write(1, "sa\n", 3);
}

void	sb(t_push_swap *ps)
{
	swap(ps->b);
	ps->benchmark.sb++;
	if (ps->flags.bench == 0)
		write(1, "sb\n", 3);
}

void	ss(t_push_swap *ps)
{
	swap(ps->a);
	swap(ps->b);
	ps->benchmark.ss++;
	if (ps->flags.bench == 0)
		write(1, "ss\n", 3);
}
