/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:34:26 by rayperei          #+#    #+#             */
/*   Updated: 2026/08/08 18:53:51 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

// verifica se a string representa um número válido
static int	is_number(char *str)
{
	int	i;

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

// verifica se o valor já existe no array já preenchido
static int	has_duplicate(int *array, int filled, int value)
{
	int	i;

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
// (ft_atol vive em utils.c, evitando duplicidade de função)
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

int	handle_flags(int argc, char **argv, int *i, t_flags flags)
{
	while (*i < argc && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (ft_strcmp(argv[*i], "--simple") == 0)
			flags.flag = 's';
		else if (ft_strcmp(argv[*i], "--medium") == 0)
			flags.flag = 'm';
		else if (ft_strcmp(argv[*i], "--complex") == 0)
			flags.flag = 'c';
		else if (ft_strcmp(argv[*i], "--adaptive") == 0)
			flags.flag = 'a';
		else if (ft_strcmp(argv[*i], "--bench") == 0)
			flags.bench = 1;
		else
			break ;
		(*i)++;
	}
	return (0);
}
