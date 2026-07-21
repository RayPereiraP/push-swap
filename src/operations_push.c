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

#include "push_swap.h"

void	pb(t_push_swap *ps)
{
	t_list	*tmp;

	if (stack->s == 0)
		return ;
	tmp = stack->a;
	stack->a = stack->a->next;
	tmp->next = stack->b;
	stack->b = tmp;
	stack->size_a--;
	stack->size_b++;
	ps->benchmark.pb++;
	write(1, "pb\n", 3);
}

void	pa(t_push_swap *ps)
{
	t_list	*tmp;

	if (stack->size_b == 0)
		return ;
	tmp = stack->b;
	stack->b = stack->b->next;
	tmp->next = stack->a;
	stack->a = tmp;
	stack->size_a++;
	stack->size_b--;
	ps->benchmark.pa++;
	write(1, "pa\n", 3);
}
