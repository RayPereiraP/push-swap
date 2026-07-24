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

t_push_swap *init_push_swap(int *array, int size, int bench, char flag)
{
    t_push_swap	*ps;

    ps = malloc(sizeof(t_push_swap));
    if (!ps)
        return (NULL);
    ps->a = init_stack(array, size);
    ps->flags.bench = bench;
    ps->flags.flag = flag;
    ps->benchmark.ra = 0;
    ps->benchmark.rb = 0;
    ps->benchmark.rr = 0;
    ps->benchmark.rra = 0;
    ps->benchmark.rrb = 0;
    ps->benchmark.rrr = 0;
    ps->benchmark.pa = 0;
    ps->benchmark.pb = 0;
    ps->benchmark.sa = 0;
    ps->benchmark.sb = 0;
    ps->benchmark.ss = 0;
    return (ps);
}

static t_stack *init_stack(int *array, int size)
{
    t_stack *stack;
    int i;
    int *idx_array;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    idx_array = index_array(array, size);
    stack->head = generate_node(array[0], idx_array[0]);
    stack->tail = NULL;
    i = 1;
    while (i < size)
    {

    }
    stack->size = 0;
    return (stack);
}

static t_list *generate_node(int value, int index)
