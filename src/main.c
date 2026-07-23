/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:24 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/22 19:50:51 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//função estática para processar as flags e avançar o índice do argv
static void handle_flags(int argc, char **argv, int *i, int *flags)
{
	while (*i < argc && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (ft_strcmp(argv[*i], "--simple") == 0) flags[0] = 1;
		else if (ft_strcmp(argv[*i], "--medium") == 0) flags[0] = 2;
		else if (ft_strcmp(argv[*i], "--complex") == 0) flags[0] = 3;
		else if (ft_strcmp(argv[*i], "--adaptive") == 0) flags[0] = 0;
		else if (ft_strcmp(argv[*i], "--bench") == 0) flags[1] = 1;
		else break;
		(*i)++;
	}
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
	int			flags[4]; // flags = algo, flags[1] = bench

	if (argc < 2)
		return (0);
	i = 1;
	flags = 0;
	flags[1] = 0;
	init_push_swap(&ps); // Inicializa structs e zera benchmark
	handle_flags(argc, argv, &i, flags);
	if (parse_arguments(argc - i, argv + i, &ps) != 0)
	{
		write(2, "Error\n", 6);
		return (free_and_exit(&ps, 1));
	}
	if (!is_sorted(ps.a))
		execute_algo(&ps, flags);
	if (flags[1])
		print_benchmark(&ps); // Exibe métricas no stderr
	free_and_exit(&ps, 0);
	return (0);
}
