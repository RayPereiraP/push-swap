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

static int *merge(int *left, int *right, int left_size, int *array, int size)
{
    int i;
    int j;
    int k;

    if (!left || !right)
        return (NULL);
    i = 0;
    j = 0;
    k = 0;
    while (i < left_size && j < size - left_size)
    {
        if (left[i] < right[j])
            array[k++] = left[i++];
        else
            array[k++] = right[j++];
    }
    while (i < left_size)
        array[k++] = left[i++];
    while (j < size - left_size)
        array[k++] = right[j++];
    return (array);
}

static int *new_array(int *array, int start, int finish)
{
    int *tmp;
    int i;

    tmp = malloc(sizeof(int) * (finish - start));
    if (!tmp)
        return (NULL);
    i = 0;
    while (start < finish)
    {
        tmp[i] = array[start];
        start++;
        i++;
    }
    return (tmp);
}

static int *merge_sort(int *array, int size)
{
    int *left;
    int *right;

    if (size > 1)
    {
        left = new_array(array, 0, size/2);
        right = new_array(array, size/2, size);
        if (!right || !left)
        {
            free(right);
            free(left);
            return (NULL);
        }
        left = merge_sort(left, size/2);
        right = merge_sort(right, (size - (size / 2)));
        array = merge(left, right, size/2, array, size);
        free(left);
        free(right);
        if (!array)
            return (NULL);
    }
    if (size == 1)
        return (array);
    return (array);
}

int  *index_array(int *stack, int size)
{
    int	*idx_array;
    int	*sorted_array;
    int	i;

    sorted_array = new_array(stack, 0, size);
    if (!sorted_array)
        return (NULL);
    sorted_array = merge_sort(sorted_array, size);
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
