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

static void	rotate(t_list **list, int size)
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
}

void	ra(t_stack *stack)
{
	rotate(&stack->a, stack->size_a);
    stack->benchmark.ra++;
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack)
{
	rotate(&stack->b, stack->size_b);
    stack->benchmark.rb++;
	write(1, "rb\n", 3);
}

void	rr(t_stack *stack)
{
	rotate(&stack->a, stack->size_a);
	rotate(&stack->b, stack->size_b);
    stack->benchmark.rr++;
	write(1, "rr\n", 3);
}
