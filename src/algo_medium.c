/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 13:00:11 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/25 13:35:08 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// encontra a posição (0-based) do menor valor na stack a
static int	get_min_position(t_stack *stack)
{
	t_list	*cur;
	int		min_value;
	int		position;
	int		i;
 
	cur = stack->head;
	min_value = cur->value;
	position = 0;
	i = 0;
	while (cur)
	{
		if (cur->value < min_value)
		{
			min_value = cur->value;
			position = i;
		}
		cur = cur->next;
		i++;
	}
	return (position);
}
 
static void	rotate_to_min(t_push_swap *ps, int min_idx)
{
	int	size;
 
	size = ps->a->size;
	if (min_idx <= size / 2)
	{
		while (min_idx > 0)
		{
			ra(ps);
			min_idx--;
		}
	}
	else
	{
		min_idx = size - min_idx;
		while (min_idx > 0)
		{
			rra(ps);
			min_idx--;
		}
	}
}
 
void	algo_medium(t_push_swap *ps)
{
	int	min_idx;
 
	if (is_sorted(ps->a))
		return ;
	while (ps->a->size > 0)
	{
		min_idx = get_min_position(ps->a);
		rotate_to_min(ps, min_idx);
		pb(ps);
	}
	while (ps->b->size > 0)
		pa(ps);
}