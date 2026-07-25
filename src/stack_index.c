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
#include <stdlib.h>

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

// swap simples de dois inteiros, usado pelo quicksort
static void	swap_int(int *a, int *b)
{
	int	tmp;
 
	tmp = *a;
	*a = *b;
	*b = tmp;
}

// particiona o array em torno de um pivô (último elemento), estilo Lomuto
static int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
 
	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
		j++;
	}
	swap_int(&arr[i + 1], &arr[high]);
	return (i + 1);
}

static void	quicksort_recursive(int *arr, int low, int high)
{
	int	pivot_index;
 
	if (low < high)
	{
		pivot_index = partition(arr, low, high);
		quicksort_recursive(arr, low, pivot_index - 1);
		quicksort_recursive(arr, pivot_index + 1, high);
	}
}

// devolve uma CÓPIA ordenada do array original (não altera o original
static int	*quicksort(int *list, int size)
{
	int	*copy;
	int	i;
 
	copy = malloc(sizeof(int) * size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < size)
	{
		copy[i] = list[i];
		i++;
	}
	quicksort_recursive(copy, 0, size - 1);
	return (copy);
}

int	*index_array(int *stack, int size)
{
	int	*idx_array;
	int	*sorted_array;
	int	i;
 
	sorted_array = quicksort(stack, size);
	if (!sorted_array)
		return (NULL);
	idx_array = malloc(sizeof(int) * size);
	if (!idx_array)
	{
		free(sorted_array);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		idx_array[i] = binary_search(sorted_array, stack[i], size);
		i++;
	}
	free(sorted_array);
	return (idx_array);
}
