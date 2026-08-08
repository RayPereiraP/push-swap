/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:24 by rayperei          #+#    #+#             */
/*   Updated: 2026/08/08 19:54:01 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// decide qual algoritmo executar, com base na flag escolhida
static void	execute_algo(t_push_swap *ps)
{
	if (ps->flags.flag == 's')
		algo_simple(ps);
	else if (ps->flags.flag == 'm')
		algo_medium(ps);
	else if (ps->flags.flag == 'c')
		algo_complex(ps);
	else
		algo_adaptive(ps);
}

static t_push_swap	*parse_and_init(int argc, char **argv, t_flags flags)
{
	t_push_swap	*ps;
	int			*array;
	int			size;
	int			i;

	i = 1;
	handle_flags(argc, argv, &i, &flags);
	if (parse_arguments(argc - i, argv + i, &array, &size) != 0)
		return (NULL);
	if (size < 2)
	{
		free(array);
		exit(0);
	}
	ps = init_push_swap(array, size, flags);
	free(array);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	t_flags		flags;
	double		disorder;

	flags = (t_flags){0};
	if (argc < 2)
		return (0);
	ps = parse_and_init(argc, argv, flags);
	if (!ps)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	disorder = compute_disorder(ps->a);
	if (!is_sorted(ps->a))
		execute_algo(ps);
	if (ps->flags.bench)
		print_benchmark(ps, disorder, ps->flags);
	free_push_swap(ps);
	return (0);
}
