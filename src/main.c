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

//função estática para processar as flags e avançar o índice do argv
static int	handle_flags(int argc, char **argv, int *i, int *flags)
{
	while (*i < argc && argv[*i] == '-' && argv[*i][1] == '-')
	{
		if (ft_strcmp(argv[*i], "--simple") == 0) flags = 1;
		else if (ft_strcmp(argv[*i], "--medium") == 0) flags = 2;
		else if (ft_strcmp(argv[*i], "--complex") == 0) flags = 3;
		else if (ft_strcmp(argv[*i], "--adaptive") == 0) flags = 0;
		else if (ft_strcmp(argv[*i], "--bench") == 0) flags[1] = 1;
		else
			break ;
		(*i)++;
	}
	return (0);
}
//decide qual dos algoritmos vai executar com base na flag ou no que for de desordem
static void execute_algo(t_push_swap *ps, int algo_flag)
{
	double disorder;
	
	disorder = compute_disorder(ps->a);
	if (algo_flag == 0) 
	{
		if (disorder < 0.2) algo_flag = 1;
		else if (disorder < 0.5) algo_flag = 2; 
		else algo_flag = 3; 
	}
	if (algo_flag == 1) algo_simple(ps);
	else if (algo_flag == 2) algo_medium(ps);
	else if (algo_flag == 3) algo_complex(ps);
}
// Função principal que faz o fluxo do programa rodar
int main(int argc, char **argv)
{
	t_push_swap	ps;
	int			i;
	int			flags[13]; // flags = algo, flags[4] = bench
	double		initial_disorder;

	if (argc < 2)
		return (0);
	i = 1;
	flags = 0;
	flags[4] = 0;
	init_push_swap(&ps); // Inicializa structs e zera benchmark
	handle_flags(argc, argv, &i, flags);
	if (parse_arguments(argc - i, argv + i, &ps) != 0)
	{
		write(2, "Error\n", 6);
		return (free_and_exit(&ps, 1));
	}
	index_stack(&ps);//para o radix
	initial_disorder = compute_disorder(ps.a);
	if (!is_sorted(ps.a))
		execute_algo(&ps, flags);
	if (flags[4])
		print_benchmark(&ps, initial_disorder, flags);// Exibe métricas no stderr
	return (free_and_exit(&ps, 0));
}
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