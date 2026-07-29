/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:49:25 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/24 16:49:25 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	generate_list(t_stack *stack, int *array, int *idx_array)
{
	t_list	*new;
	int		i;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = array[0];
	new->index = idx_array[0];
	new->next = NULL;
	stack->head = new;
	stack->tail = new;
	i = 1;
	while (i < stack->size)
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (0);
		new->value = array[i];
		new->index = idx_array[i];
		new->next = NULL;
		stack->tail->next = new;
		stack->tail = new;
		i++;
	}
	return (1);
}

static t_stack	*init_stack(int *array, int size)
{
	t_stack	*stack;
	int		*idx_array;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = size;
	stack->head = NULL;
	stack->tail = NULL;
	idx_array = index_array(array, size);
	if (!idx_array)
	{
		free_stack(stack);
		return (NULL);
	}
	if (!generate_list(stack, array, idx_array))
	{
		free(idx_array);
		free_stack(stack);
		return (NULL);
	}
	free(idx_array);
	return (stack);
}

static t_stack	*init_empty_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

static t_benchmark	init_benchmark(void)
{
	t_benchmark	benchmark;

	benchmark.ra = 0;
	benchmark.rb = 0;
	benchmark.rr = 0;
	benchmark.rra = 0;
	benchmark.rrb = 0;
	benchmark.rrr = 0;
	benchmark.pa = 0;
	benchmark.pb = 0;
	benchmark.sa = 0;
	benchmark.sb = 0;
	benchmark.ss = 0;
	return (benchmark);
}

t_push_swap	*init_push_swap(int *array, int size, int bench, char flag)
{
	t_push_swap	*ps;

	ps = malloc(sizeof(t_push_swap));
	if (!ps)
		return (NULL);
	ps->a = init_stack(array, size);
	ps->b = init_empty_stack();
	if (!ps->a || !ps->b)
	{
		free_push_swap(ps);
		return (NULL);
	}
	ps->flags.bench = bench;
	ps->flags.flag = flag;
	ps->benchmark = init_benchmark();
	return (ps);
}
