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

#include "push_swap.h"

static void	swap(t_list **list, int size)
{
	t_list	*tmp;

	if (size <= 1)
		return ;
	tmp = (*list)->next;
	(*list)->next = tmp->next;
	tmp->next = *list;
	*list = tmp;
}

void	sa(t_stack *stack)
{
	swap(&stack->a, stack->size_a);
    stack->benchmark.sa++;
	write(1, "sa\n", 3);
}

void	sb(t_stack *stack)
{
	swap(&stack->b, stack->size_b);
    stack->benchmark.sb++;
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack)
{
	swap(&stack->a, stack->size_a);
	swap(&stack->b, stack->size_b);
    stack->benchmark.ss++;
	write(1, "ss\n", 3);
}
