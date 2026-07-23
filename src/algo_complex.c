/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:11 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/22 21:10:08 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//radix sort
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

static void apply_indices(t_push_swap *ps, int *indexed_values)
{
	t_list  *curr;
	int		i;

	curr = ps->a->head;
	i = 0;
	while (curr)
	{
		curr->value = indexed_values[i++];
		curr = curr->next;
	}
}

static void	index_stack(t_push_swap *ps)
{
	t_list	*curr;
	int		*val;
	int		i;

	val = malloc(sizeof(int) * ps->a->size);
	if (!val)
		return ;
	curr = ps->a->head;
	i = 0;
	while (curr)
	{
		val[i++] = get_index(ps->a->head, curr->value);
		curr = curr->next;
	}
	apply_indices(ps, val);
	free(val);
}

// Função para processar os bits (extraída para reduzir linhas)
static void	process_bits(t_push_swap *ps, int bit_pos)
{
	int	j;
	int	size;

	j = 0;
	size = ps->a->size;
	while (j < size)
	{
		if (((ps->a->head->value >> bit_pos) & 1) == 1)
			ra(ps);
		else
			pb(ps);
		j++;
	}
	while (ps->b->size > 0)
		pa(ps);
}

void	algo_complex(t_push_swap *ps)
{
	int	i;
	int	max_bits;

	index_stack(ps);
	max_bits = get_max_bits(ps->a->size);
	i = 0;
	while (i < max_bits)
	{
		process_bits(ps, i);
		i++;
	}
}


/*
//Quicksort
//desfazer as rotações e restaurar a pilha (Backtracking)
static void	backtrack(t_push_swap *ps, int stack_id, int rotations)
{
	while (rotations-- > 0)
	{
		if (stack_id == 'a')
			rra(ps);
		else
			rrb(ps);
	}
}

// Particiona a Pilha A: joga quem é menor que o pivô para a Pilha B
static int	partition_a(t_push_swap *ps, int size)
{
	int	pushed;
	int	rotations;
	int	pivot;

	pushed = 0;
	rotations = 0;
	pivot = get_median(ps->a, size); // Você deve implementar a busca da mediana
	while (size-- > 0)
	{
		if (ps->a->head->value < pivot)
		{
			pb(ps);
			pushed++;
		}
		else
		{
			ra(ps);
			rotations++;
		}
	}
	backtrack(ps, 'a', rotations);
	return (pushed);
}

// A lógica principal recursiva para a Pilha A
void	quicksort_a(t_push_swap *ps, int size)
{
	int	pushed;

	if (size <= 2)
	{
		if (size == 2 && ps->a->head->value > ps->a->head->next->value)
			sa(ps);
		return ;
	}
	pushed = partition_a(ps, size);
	quicksort_a(ps, size - pushed); // Ordena o que ficou em A (maiores)
	quicksort_b(ps, pushed);       // Ordena o que foi para B (menores)
}

// O algoritmo complexo orquestrador
void	algo_complex(t_push_swap *ps)
{
	if (is_sorted(ps->a))
		return ;
	// Opcional: index_stack(ps); // Facilita encontrar a mediana se usar índices
	quicksort_a(ps, ps->a->size);
}
*/