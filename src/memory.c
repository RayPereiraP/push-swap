/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:12:05 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/22 21:26:44 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//funções de limpeza de memória - por conta do uso de memória dinamicamente (malloc) precisa disso, senão sobra memory leak
#include "push_swap.h"
#include <stdlib.h>

static void	free_stack(t_stack *stack)
{
	t_list	*curr;
	t_list	*tmp;

	if (!stack)
		return ;
	curr = stack->head;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
	free(stack);
}

void	free_all(t_push_swap *ps)
{
	free_stack(ps->a);
	free_stack(ps->b);
}

int	free_and_exit(t_push_swap *ps, int status)
{
	free_all(ps);
	return (status);
}
