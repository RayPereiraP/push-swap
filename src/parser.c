/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 12:15:16 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/23 14:34:11 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

//verifica se não numeros 
static int      is_number(char *str)
{
	int 	i;
	
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
//conversão da string para long para detectar o int min e o max
static long		ft_atol(const char *str)
{
	long	res;
	int 	sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

//verifiac na pilha a se o valor já existe - duplicatas
static int 		has_duplicate(t_stack *stack, int value)
{
	t_list	*curr;

	curr = stack->head;
	while (curr)
	{
		if (curr->value == value)
			return (1);
		curr = curr->next;
	}
	return (0);
}

//cria um novo nó e add no final de A 
static int 		add_to_stack(t_stack *stack, int value)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (1);
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		stack->tail = new_node;
	}
	stack->size++;
	return (0);
}

//função principal do parser chamada pelo main.c
int 	parse_arguments(int argc, char **argv, t_push_swap *ps)
{
	int 	i;
	long	value;

	i = 0;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (1);
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			return (1);
		if (has_duplicate(ps->a, (int)value))
			return (1);
		if (add_to_stack(ps->a, (int)value) != 0)
			return (1);
		i++;
	}
	return (0);
}
