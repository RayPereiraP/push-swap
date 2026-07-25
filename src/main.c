/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:24 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/23 14:39:24 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

// decide qual algoritmo executar, com base na flag escolhida
static void	execute_algo(t_push_swap *ps, int algo_flag)
{
	if (algo_flag == 1)
		algo_simple(ps);
	else if (algo_flag == 2)
		algo_medium(ps);
	else if (algo_flag == 3)
		algo_complex(ps);
	else
		algo_adaptive(ps);
}
 
static t_push_swap	*parse_and_init(int argc, char **argv, int *flags)
{
	t_push_swap	*ps;
	int			*array;
	int			size;
	int			i;

	i = 1;
	flags[0] = 0;
	flags[1] = 0;
	handle_flags(argc, argv, &i, flags);
	if (parse_arguments(argc - i, argv + i, &array, &size) != 0)
		return (NULL);
	if (size < 2)
	{
		free(array);
		exit(0);
	}
	ps = init_push_swap(array, size, flags[1], (char)flags[0]);
	free(array);
	return (ps);
}

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			flags[2];
	double		disorder;

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
		execute_algo(ps, flags[0]);
	if (flags[1])
		print_benchmark(ps, disorder, flags);
	free_push_swap(ps);
	return (0);
}
