/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:04 by rayperei          #+#    #+#             */
/*   Updated: 2026/08/08 20:38:49 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../inc/push_swap.h"

static int	get_total_ops(t_benchmark *b)
{
	return (b->sa + b->sb + b->ss + b->pa + b->pb + b->ra + b->rb + b->rr
		+ b->rra + b->rrb + b->rrr);
}

static char	*get_strategy_info(char algo_flag, double disorder)
{
	if (algo_flag == 's')
		return ("Simple / O(n^2)");
	if (algo_flag == 'm')
		return ("Medium / O(n√n)");
	if (algo_flag == 'c')
		return ("Complex / O(n log n)");
	else
	{
		if (disorder < 0.2)
			return ("Adaptive / O(n^2)");
		else if (disorder < 0.5)
			return ("Adaptive / O(n√n)");
		else
			return ("Adaptive / O(n log n)");
	}
}

static void	print_ops_breakdown(t_benchmark *b)
{
	ft_printf("[bench] sa: %d | sb: %d | ss: %d\n", b->sa, b->sb, b->ss);
	ft_printf("[bench] pa: %d | pb: %d\n", b->pa, b->pb);
	ft_printf("[bench] ra: %d | rb: %d | rr: %d\n", b->ra, b->rb, b->rr);
	ft_printf("[bench] rra: %d | rrb: %d | rrr: %d\n", b->rra, b->rrb, b->rrr);
}

void	print_benchmark(t_push_swap *ps, double initial_disorder, t_flags flags)
{
	int	total_ops;

	total_ops = get_total_ops(&ps->benchmark);
	ft_printf("[bench] disorder: %p\n", initial_disorder);
	ft_printf("[bench] strategy: %s\n", get_strategy_info(flags.flag,
			initial_disorder));
	ft_printf("[bench] total_ops: %d\n", total_ops);
	print_ops_breakdown(&ps->benchmark);
}
