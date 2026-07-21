/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:24 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 17:24:48 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Extraímos a lógica de parsing das flags para uma função separada
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

static void execute_algo(t_stack *stack, int algo_flag)
{
	double disorder = compute_disorder(stack);

	if (algo_flag == 0) 
	{
		if (disorder < 0.2) algo_flag = 1;
		else if (disorder < 0.5) algo_flag = 2; 
		else algo_flag = 3; 
	}
	if (algo_flag == 1) algo_simple(stack);
	else if (algo_flag == 2) algo_medium(stack);
	else if (algo_flag == 3) algo_complex(stack);
}

int main(int argc, char **argv)
{
	t_stack stack;
	int		i = 1;
	int		flags[2] = {0, 0}; // flags[0] = algo, flags[1] = bench

	if (argc < 2) return (0);
	init_stack(&stack);
	handle_flags(argc, argv, &i, flags);
	if (parse_arguments(argc - i, argv + i, &stack) != 0)
	{
		write(2, "Error\n", 6);
		return (free_and_exit(&stack));
	}
	if (!is_sorted(&stack))
		execute_algo(&stack, flags[0]);
	// if (flags[1]) print_benchmark(&stack, ...);
	free_stack(&stack);
	return (0);
}
