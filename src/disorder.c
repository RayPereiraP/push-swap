/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 17:34:37 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/18 17:34:37 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

double	compute_disorder(t_stack *stack)
{
	int		mistakes;
	int		total_pairs;
	t_list	*cur;
	t_list	*next;

	if (stack->size < 2)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	cur = stack->head;
	while (cur)
	{
		next = cur->next;
		while (next)
		{
			total_pairs++;
			if (cur->value > next->value)
				mistakes++;
			next = next->next;
		}
		cur = cur->next;
	}
	return ((double)mistakes / total_pairs);
}
