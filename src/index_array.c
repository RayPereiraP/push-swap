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

#include "../inc/push_swap.h"

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

static void	merge(int *array, int *sorted, int start, int finish)
{
	int	i;
	int	j;
	int	k;
	int	middle;

	middle = start + (finish - start) / 2;
	i = start;
	j = middle + 1;
	k = start;
	while (i <= middle && j <= finish)
	{
		if (array[i] < array[j])
			sorted[k++] = array[i++];
		else
			sorted[k++] = array[j++];
	}
	while (i <= middle)
		sorted[k++] = array[i++];
	while (j <= finish)
		sorted[k++] = array[j++];
	i = start - 1;
	while (++i <= finish)
		array[i] = sorted[i];
}

static void	merge_sort(int *array, int *sorted, int start, int finish)
{
	int	middle;

	if (start < finish)
	{
		middle = start + (finish - start) / 2;
		merge_sort(array, sorted, start, middle);
		merge_sort(array, sorted, middle + 1, finish);
		merge(array, sorted, start, finish);
	}
}

static int	*init_merge_sort(int *array, int size)
{
	int	*buffer;
	int	*sorted;
	int	i;

	i = 0;
	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return (NULL);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(buffer);
		return (NULL);
	}
	while (i < size)
	{
		sorted[i] = array[i];
		i++;
	}
	merge_sort(sorted, buffer, 0, size - 1);
	free(buffer);
	return (sorted);
}

int	*index_array(int *stack, int size)
{
	int	*idx_array;
	int	*sorted_array;
	int	i;

	sorted_array = init_merge_sort(stack, size);
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
