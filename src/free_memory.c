/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:12:49 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/24 18:12:49 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_list(t_list *list)
{
	t_list	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	free_list(stack->head);
	free(stack);
}

void	free_push_swap(t_push_swap *ps)
{
	if (ps->a)
		free_stack(ps->a);
	if (ps->b)
		free_stack(ps->b);
	free(ps);
}
