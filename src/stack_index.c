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

static int	binary_search(int *list, int value, int size)
{
	int	start;
	int	end;
	int	mid;

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

static int	*merge(int *array, int *sorted, int start, int middle, int finish)
{
	int	i;
	int	j;
	int	k;

	i = start;
	j = middle + 1;
	k = start;
	while (i < middle && j < finish - middle)
	{
		if (array[i] < array[j])
			sorted[k++] = array[i++];
		else
            sorted[k++] = array[j++];
	}
	return (array);
}

static int	*merge_sort(int *array, int *sorted, int start, int finish)
{
	int	middle;

	if (start < finish)
	{
		middle = start + (finish - start) / 2;
		merge_sort(array, sorted, start, middle);
		merge_sort(array, sorted, middle + 1, finish);
		merge(array, sorted, start, middle, finish);
	}
	else
		return (array);
}

int	*index_array(int *stack, int size)
{
	int	*idx_array;
	int	*sorted_array;
	int	i;

	sorted_array = malloc(sizeof(int) * size);
	if (!sorted_array)
		return (NULL);
	merge_sort(stack, sorted_array, 0, size);
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
