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

#include "push_swap.h"

static t_list	*generate_node(int value, int index)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

static t_stack	*init_stack(int *array, int size)
{
	t_stack	*stack;
	int		i;
	int		*idx_array;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	idx_array = index_array(array, size);
	stack->head = generate_node(array[0], idx_array[0]);
    if (!stack->head)
        return (NULL);
	stack->tail = stack->head;
	i = 1;
	while (i < size)
	{
		stack->tail->next = generate_node(array[i], idx_array[i]);
        if (!stack->tail->next)
            return (NULL);
        stack->tail = stack->tail->next;
        i++;
	}
	stack->size = size;
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

static t_benchmark init_benchmark(void)
{
    t_benchmark benchmark;

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
