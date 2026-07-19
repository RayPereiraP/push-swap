/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:11 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 15:14:50 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

static void index_stack(t_stack *stack)
{
    t_list  *curr;
    t_list  *compare;
    int     index;
    int     *indexed_values;
    int     i;

    indexed_values = malloc(sizeof(int) * stack->size_a);
    if (!indexed_values)
        return ;
    curr = stack->a;
    i = 0;
    while (curr)
    {
        index = 0;
        compare = stack->a;
        while (compare)
        {
            if (curr->value > compare->value)
                index++;
            compare = compare->next;
        }
        indexed_values[i++] = index;
        curr = curr->next;
    }
    curr = stack->a;
    i = 0;
    while (curr)
    {
        curr->value = indexed_values[i++]; 
        curr = curr->next;
    }
    free(indexed_values); 
}

void algo_complex(t_stack *stack)
{
    int i;
    int j;
    int size;
    int max_bits;

    index_stack(stack);

    max_bits = get_max_bits(stack);
    size = stack->size_a;

    i = 0;
    while (i < max_bits)
    {
        j = 0;
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
        i++;
    }
}
