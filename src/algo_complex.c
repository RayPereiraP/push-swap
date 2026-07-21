/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:11 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 17:19:23 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(t_stack *stack)
{
	int max_index;
	int max_bits;

	max_index = stack->size_a - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void apply_indices(t_stack *stack, int *indexed_values)
{
	t_list  *curr;
	int		i;

	curr = stack->a;
	i = 0;
	while (curr)
	{
		curr->value = indexed_values[i++];
		curr = curr->next;
	}
}

static void index_stack(t_stack *stack)
{
	t_list	*curr = stack->a;
	int		*indexed_values = malloc(sizeof(int) * stack->size_a);
	int		i = 0;

	if (!indexed_values)
		return;
	while (curr)
	{
		int index = 0;
		t_list *compare = stack->a;
	while (compare)
		{
			if (curr->value > compare->value && ++index)
				;
			compare = compare->next;
		}
		indexed_values[i++] = index;
		curr = curr->next;
	}
	apply_indices(stack, indexed_values);
	free(indexed_values);
}

// Função para processar os bits (extraída para reduzir linhas)
static void process_bits(t_stack *stack, int i)
{
	int j;
	int size;

	j = 0;
	size = stack->size_a;
	while (j < size)
	{
		if (((stack->a->value >> i) & 1) == 1)
			ra(stack);
		else
			pb(stack);
		j++;
	}
	while (stack->size_b > 0)
		pa(stack);
}

void algo_complex(t_stack *stack)
{
	int i;
	int max_bits;

	index_stack(stack);
	max_bits = get_max_bits(stack);
	i = 0;
	while (i < max_bits)
	{
		process_bits(stack, i);
		i++;
	}
}
