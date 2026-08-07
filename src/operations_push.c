/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 11:50:44 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/18 11:50:44 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pb(t_push_swap *ps)
{
	t_list	*tmp;

	if (ps->a->size == 0)
		return ;
	tmp = ps->a->head;
	ps->a->head = ps->a->head->next;
	tmp->next = ps->b->head;
	ps->b->head = tmp;
	ps->a->size--;
	if (ps->a->size == 0)
		ps->a->tail = NULL;
	else if (ps->a->size == 1)
		ps->a->tail = ps->a->head;
	ps->b->size++;
	if (ps->b->size == 1)
		ps->b->tail = ps->b->head;
	ps->benchmark.pb++;
	if (ps->flags.bench == 0)
		write(1, "pb\n", 3);
}

void	pa(t_push_swap *ps)
{
	t_list	*tmp;

	if (ps->b->size == 0)
		return ;
	tmp = ps->b->head;
	ps->b->head = ps->b->head->next;
	tmp->next = ps->a->head;
	ps->a->head = tmp;
	ps->b->size--;
	if (ps->b->size == 0)
		ps->b->tail = NULL;
	else if (ps->b->size == 1)
		ps->b->tail = ps->b->head;
	ps->a->size++;
	if (ps->a->size == 1)
		ps->a->tail = ps->a->head;
	ps->benchmark.pa++;
	if (ps->flags.bench == 0)
		write(1, "pa\n", 3);
}
