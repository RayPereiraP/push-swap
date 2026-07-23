/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/22 13:12:05 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/22 21:26:44 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// para calcular o total de operações somando todos os contadores da struct 
static int	get_total_ops(t_benchmark *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb + b->ra
		+ b->rb + b->rr + b->rra + b->rrb + b->rrr);
}

//retorno da string com o nome e qual algoritmo 
static char	*get_strategy_info(int algo_flag)
{
	if (algo_flag == 1)
		return ("Simple / O(n²)");
	if (algo_flag == 2)
		return ("Medium / O(n√n)");
	if (algo_flag == 3)
		return ("Complex / O(n log n)");
	return ("Adaptive / Automático");
}

//validação do desempenho: se atingiu as metas de nota máxima 
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

//o que mais seria interessante colocar aqui?
// comparar o limite final das listas?
//aqui que vai os limites dos testes?
