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

static void	reverse_rotate(t_list **list, int size)
{
	t_list	*tail;
	t_list	*tmp;

	if (size <= 1)
		return ;
	tail = *list;
	while (tail->next)
	{
		tail = tail->next;
		tmp = tail;
	}
	tmp->next = NULL;
	tail->next = *list;
	*list = tail;
}

void	rra(t_stack *stack)
{
	reverse_rotate(&stack->a, stack->size_a);
    stack->benchmark.rra++;
	write(1, "rra\n", 3);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(&stack->b, stack->size_b);
    stack->benchmark.rrb++;
	write(1, "rrb\n", 3);
}

void	rrr(t_stack *stack)
{
	reverse_rotate(&stack->a, stack->size_a);
	reverse_rotate(&stack->b, stack->size_b);
    stack->benchmark.rrr++;
	write(1, "rrr\n", 3);
}