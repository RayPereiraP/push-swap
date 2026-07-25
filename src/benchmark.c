/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:34:26 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/23 14:34:35 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// para calcular o total de operações somando todos os contadores da struct
static int	get_total_ops(t_benchmark *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb + b->ra
		+ b->rb + b->rr + b->rra + b->rrb + b->rrr);
}

// retorno da string com o nome e qual algoritmo
static char	*get_strategy_info(int algo_flag)
{
	if (algo_flag == 1)
		return ("Simple / O(n^2)");
	if (algo_flag == 2)
		return ("Medium / O(n sqrt n)");
	if (algo_flag == 3)
		return ("Complex / O(n log n)");
	return ("Adaptive / Automatico");
}

// validação do desempenho: se atingiu as metas de nota máxima
static void	check_performance(int size, int total_ops)
{
	fprintf(stderr, "Performance: ");
	if (size <= 100 && total_ops < 700)
		fprintf(stderr, "EXCELLENT (< 700 ops)\n");
	else if (size <= 500 && total_ops < 5500)
		fprintf(stderr, "EXCELLENT (< 5500 ops)\n");
	else
		fprintf(stderr, "Standard (Check PUSH.pdf limits)\n");
}

// imprime o breakdown de cada operação individual
static void	print_ops_breakdown(t_benchmark *b)
{
	fprintf(stderr, "--- Operations breakdown ---\n");
	fprintf(stderr, "sa: %d | sb: %d | ss: %d\n", b->sa, b->sb, b->ss);
	fprintf(stderr, "pa: %d | pb: %d\n", b->pa, b->pb);
	fprintf(stderr, "ra: %d | rb: %d | rr: %d\n", b->ra, b->rb, b->rr);
	fprintf(stderr, "rra: %d | rrb: %d | rrr: %d\n", b->rra, b->rrb, b->rrr);
}

// função principal do benchmark, chamada pelo main.c quando --bench está ativa
void	print_benchmark(t_push_swap *ps, double initial_disorder, int *flags)
{
	int	total_ops;
	int	size;

	total_ops = get_total_ops(&ps->benchmark);
	size = ps->a->size + ps->b->size;
	fprintf(stderr, "========= BENCHMARK =========\n");
	fprintf(stderr, "Size: %d\n", size);
	fprintf(stderr, "Initial disorder: %.4f\n", initial_disorder);
	fprintf(stderr, "Strategy: %s\n", get_strategy_info(flags[0]));
	print_ops_breakdown(&ps->benchmark);
	fprintf(stderr, "Total operations: %d\n", total_ops);
	if (size > 0)
		fprintf(stderr, "Ops/size ratio: %.4f\n", (double)total_ops / size);
	check_performance(size, total_ops);
	fprintf(stderr, "==============================\n");
}
