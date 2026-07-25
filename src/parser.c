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
#include <stdlib.h>
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
static int 		has_duplicate(int *array, int filled, int value)
{
	i = 0;
	while (i < filled)
	{
		if (array[i] == value)
			return (1);
		i++;
	}
	return (0);
}

// valida e converte um argv[i] em int, checando overflow e duplicata
static int	validate_and_convert(char *str, int *array, int filled, int *out)
{
	long	value;
 
	if (!is_number(str))
		return (1);
	value = ft_atol(str);
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	if (has_duplicate(array, filled, (int)value))
		return (1);
	*out = (int)value;
	return (0);
}
 
// função principal do parser, chamada pelo main.c
// devolve 0 em sucesso (com *array e *size preenchidos) ou 1 em erro
int	parse_arguments(int argc, char **argv, int **array, int *size)
{
	int	*result;
	int	i;
 
	if (argc <= 0)
		return (1);
	result = malloc(sizeof(int) * argc);
	if (!result)
		return (1);
	i = 0;
	while (i < argc)
	{
		if (validate_and_convert(argv[i], result, i, &result[i]) != 0)
		{
			free(result);
			return (1);
		}
		i++;
	}
	*array = result;
	*size = argc;
	return (0);
}
