/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:04 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 15:18:36 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_min_index(t_stack *stack)
{
    int     min_val;
    int     min_idx;
    int     curr_idx;
    t_list  *tmp;

    if (!stack || !stack->a)
        return (0);
    tmp = stack->a;
    min_val = tmp->value;
    min_idx = 0;
    curr_idx = 0;
    
    while (tmp)
    {
        if (tmp->value < min_val)
        {
            min_val = tmp->value;
            min_idx = curr_idx;
        }
        tmp = tmp->next;
        curr_idx++;
    }
    return (min_idx);
}

void algo_simple(t_stack *stack)
{
    int min_idx;

    while (stack->size_a > 0)
    {
        min_idx = get_min_index(stack);

        if (min_idx <= stack->size_a / 2)
        {
            while (min_idx > 0)
            {
                ra(stack);
                min_idx--;
            }
        }
        
        else
        {
            while (min_idx < stack->size_a)
            {
                rra(stack);
                min_idx++;
            }
        }
        
        pb(stack);
    }

    while (stack->size_b > 0)
    {
        pa(stack);
    }
}