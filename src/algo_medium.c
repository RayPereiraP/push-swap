/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 09:57:23 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/28 09:57:23 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	process_a(t_push_swap *ps, int position)
{
	if (position < ps->a->size / 2)
	{
		while (position)
		{
			ra(ps);
			position--;
		}
	}
	else
	{
		while (position < ps->a->size)
		{
			rra(ps);
			position++;
		}
	}
	pb(ps);
	if (ps->b->size > 1 && ps->b->head->index < ps->b->head->next->index)
	{
		sb(ps);
	}
}

static void	process_b(t_push_swap *ps)
{
	t_list	*tmp;
	int		position;

	tmp = ps->b->head;
	position = 0;
	while (tmp && tmp->index != ps->b->size - 1)
	{
		tmp = tmp->next;
		position++;
	}
	if (position < ps->b->size / 2)
	{
		while (position--)
			rb(ps);
	}
	else
	{
		while (position++ < ps->b->size)
			rrb(ps);
	}
	pa(ps);
}

static int	find_position_next(t_stack *stack, int start_index,
		int finish_index)
{
	t_list	*tmp;
	int		first_position;
	int		last_position;
	int		position;

	tmp = stack->head;
	first_position = -1;
	last_position = -1;
	position = 0;
	while (tmp)
	{
		if (tmp->index >= start_index && tmp->index <= finish_index)
		{
			if (first_position == -1)
				first_position = position;
			last_position = position;
		}
		tmp = tmp->next;
		position++;
	}
	if (first_position <= ((stack->size - last_position)))
		return (first_position);
	return (last_position);
}

void	algo_medium(t_push_swap *ps)
{
	int	bc;
	int	bs;
	int	bp;
	int	i;

	bc = ft_sqrt(ps->a->size);
	bs = ps->a->size / bc;
	i = 0;
	while (i < bc)
	{
		bp = 0;
		while (bp < bs)
		{
			process_a(ps, find_position_next(ps->a, i * bs, (i * bs) + bs - 1));
			bp++;
		}
		i++;
	}
	while (ps->a->size > 0)
		process_a(ps, find_position_next(ps->a, i * bs, (i * bs) + bs - 1));
	while (ps->b->size)
		process_b(ps);
}
