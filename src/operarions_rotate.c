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

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_list	*head;
	t_list	*tmp;

	if (size <= 1)
		return ;
	head = *list;
	*list = (*list)->next;
	head->next = NULL;
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = head;
	*tail = head;
}

void	ra(t_push_swap *ps)
{
	rotate(ps->a);
    ps->benchmark.ra++;
	write(1, "ra\n", 3);
}

void	rb(t_push_swap *ps)
{
	rotate(ps->b);
    ps->benchmark.rb++;
	write(1, "rb\n", 3);
}

void	rr(t_push_swap *ps)
{
	rotate(ps->a);
	rotate(ps->b);
    ps->benchmark.rr++;
	write(1, "rr\n", 3);
}
