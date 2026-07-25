/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:38:32 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/23 12:38:32 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int binary_search(int *list, int value, int size)
{
    int start;
    int end;
    int mid;
    
    start = 0;
    end = size - 1;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (value < list[mid])
            end = mid - 1;
        else if (value > list[mid])
            start = mid + 1;
        else
            return (mid);
    }
    return (-1);
}

static int *quicksort(int *list, int size)
{
    
}
void stack_index(int *stack)
{
    int	i;

}


