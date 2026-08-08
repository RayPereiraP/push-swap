/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:04 by rayperei          #+#    #+#             */
/*   Updated: 2026/08/08 19:09:27 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	get_total_ops(t_benchmark *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb + b->ra
		+ b->rb + b->rr + b->rra + b->rrb + b->rrr);
}

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

static void	print_ops_breakdown(t_benchmark *b)
{
	fprintf(stderr, "[bench] sa: %d | sb: %d | ss: %d\n",
		b->sa, b->sb, b->ss);
	fprintf(stderr, "[bench] pa: %d | pb: %d\n", b->pa, b->pb);
	fprintf(stderr, "[bench] ra: %d | rb: %d | rr: %d\n",
		b->ra, b->rb, b->rr);
	fprintf(stderr, "[bench] rra: %d | rrb: %d | rrr: %d\n",
		b->rra, b->rrb, b->rrr);
}

void	print_benchmark(t_push_swap *ps, double initial_disorder, t_flags flags)
{
	int	total_ops;

	total_ops = get_total_ops(&ps->benchmark);
	fprintf(stderr, "[bench] disorder: %.2f%%\n", initial_disorder * 100);
	fprintf(stderr, "[bench] strategy: %s\n", get_strategy_info(flags.strategy));
	fprintf(stderr, "[bench] total_ops: %d\n", total_ops);
	print_ops_breakdown(&ps->benchmark);
}
