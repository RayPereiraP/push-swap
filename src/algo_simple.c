/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:04 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/22 11:34:46 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//para rodar na A e trazer o menor nº até o topo, decide se vai mais rápido ou em cima ou para baixo
static void rotate_to_min(t_stack *data, int min_idx)
{
	int	size;

	size = data->size_a;
	if (min_idx <= size / 2)
	{
		while (min_idx > 0)
		{
			op_ra(data, 1);
			min_idx--;
		}
	}
	else
	{
		min_idx = size - min_idx;
		while (min_idx > 0)
		{
			op_rra(data, 1);
			min_idx--;
		}
	}
}
//verificação de ordenação - se ok, para
void algo_simple(t_stack *data)
{
	int	min_idx;

	if (is_sorted(data->stack_a))
		return ;
	while (data->size_a > 0)
	{
		min_idx = find_position(data->stack_a, stack_min_index(data->stack_a));
		rotate_to_min(data, min_idx);
		op_pb(data, 1);
	}
	while (data->size_b > 0)
		op_pa(data, 1);
}
