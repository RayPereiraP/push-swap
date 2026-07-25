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
 
int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			i;
	int			flags[2]; // flags[0] = algoritmo, flags[1] = bench
	int			*array;
	int			size;
	double		initial_disorder;
 
	if (argc < 2)
		return (0);
	i = 1;
	flags[0] = 0;
	flags[1] = 0;
	handle_flags(argc, argv, &i, flags);
	if (parse_arguments(argc - i, argv + i, &array, &size) != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (size < 2)
	{
		free(array);
		return (0);
	}
	ps = init_push_swap(array, size, flags[1], (char)flags[0]);
	free(array);
	if (!ps)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	initial_disorder = compute_disorder(ps->a);
	if (!is_sorted(ps->a))
		execute_algo(ps, flags[0]);
	if (flags[1])
		print_benchmark(ps, initial_disorder, flags);
	free_push_swap(ps);
	return (0);
}


/*
// processa as flags e avança o índice do argv
static int	handle_flags(int argc, char **argv, int *i, int *flags)
{
	while (*i < argc && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (ft_strcmp(argv[*i], "--simple") == 0)
			flags[0] = 1;
		else if (ft_strcmp(argv[*i], "--medium") == 0)
			flags[0] = 2;
		else if (ft_strcmp(argv[*i], "--complex") == 0)
			flags[0] = 3;
		else if (ft_strcmp(argv[*i], "--adaptive") == 0)
			flags[0] = 0;
		else if (ft_strcmp(argv[*i], "--bench") == 0)
			flags[1] = 1;
		else
			break ;
		(*i)++;
	}
	return (0);
}

// decide qual algoritmo executar, com base na flag ou no nível de desordem
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

int	main(int argc, char **argv)
{
	t_push_swap	*ps;
	int			i;
	int			flags[2]; // flags[0] = algoritmo, flags[1] = bench
	int			*array;
	int			size;
	double		initial_disorder;

	if (argc < 2)
		return (0);
	i = 1;
	flags[0] = 0;
	flags[1] = 0;
	handle_flags(argc, argv, &i, flags);
	if (parse_arguments(argc - i, argv + i, &array, &size) != 0)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (size < 2)
	{
		free(array);
		return (0);
	}
	ps = init_push_swap(array, size, flags[1], (char)flags[0]);
	free(array);
	if (!ps)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	initial_disorder = compute_disorder(ps->a);
	if (!is_sorted(ps->a))
		execute_algo(ps, flags[0]);
	if (flags[1])
		print_benchmark(ps, initial_disorder, flags);
	free_push_swap(ps);
	return (0);
*/

/*
int	main(int argc, char **argv)
{
	t_push_swap	ps;
	int			i;

	if (argc < 2)
		return (0);
	init_push_swap(&ps);
	i = 1; // Pula o nome do programa (argv[0])
	handle_flags(argc, argv, &i, &ps); // Le as flags e avança o 'i'
	if (i >= argc) // Se só passaram flags sem números
		return (0);
	if (parse_arguments(argc, argv, i, &ps) != 0)
	{
		write(2, "Error\n", 6); // Requisito do Wesley/42
		free_all(&ps);
		return (1);
	}
	
	solve(&ps);
	if (ps.is_bench)
		print_benchmark(&ps);

	free_all(&ps);
	return (0);
}
*/