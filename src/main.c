/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:24 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 15:25:26 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int ft_strcmp(const char *s1, const char *s2)
{
    while (*s1 && *s1 == *s2)
    {
        s1++;
        s2++;
    }
    return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static void init_stack(t_stack *stack)
{
    stack->a = NULL;
    stack->b = NULL;
    stack->size_a = 0;
    stack->size_b = 0;
    stack->benchmark.sa = 0;
    stack->benchmark.sb = 0;
    stack->benchmark.ss = 0;
    stack->benchmark.pa = 0;
    stack->benchmark.pb = 0;
    stack->benchmark.ra = 0;
    stack->benchmark.rb = 0;
    stack->benchmark.rr = 0;
    stack->benchmark.rra = 0;
    stack->benchmark.rrb = 0;
    stack->benchmark.rrr = 0;
}

static int is_sorted(t_stack *stack)
{
    t_list *tmp;

    if (!stack->a)
        return (1);
    tmp = stack->a;
    while (tmp->next)
    {
        if (tmp->value > tmp->next->value)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int	main(int argc, char **argv)
{
    t_stack stack;
    int     i;
    int     algo_flag;
    int     bench_flag;
    double  disorder;

    if (argc < 2)
        return (0);

    init_stack(&stack);
    i = 1;
    algo_flag = 0;
    bench_flag = 0;

    while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
    {
        if (ft_strcmp(argv[i], "--simple") == 0)
            algo_flag = 1;
        else if (ft_strcmp(argv[i], "--medium") == 0)
            algo_flag = 2;
        else if (ft_strcmp(argv[i], "--complex") == 0)
            algo_flag = 3;
        else if (ft_strcmp(argv[i], "--adaptive") == 0)
            algo_flag = 0;
        else if (ft_strcmp(argv[i], "--bench") == 0)
            bench_flag = 1;
        else
            break;
        i++;
    }

    if (parse_arguments(argc - i, argv + i, &stack) != 0)
    {
        write(2, "Error\n", 6);
        free_stack(&stack);
        return (1);
    }

    if (is_sorted(&stack))
    {
        free_stack(&stack);
        return (0);
    }

    disorder = compute_disorder(&stack);

    if (algo_flag == 0) 
    {
        if (disorder < 0.2)
            algo_flag = 1;
        else if (disorder < 0.5)
            algo_flag = 2; 
        else
            algo_flag = 3; 
    }

    if (algo_flag == 1)
        algo_simple(&stack);
    else if (algo_flag == 2)
        algo_medium(&stack);
    else if (algo_flag == 3)
        algo_complex(&stack);

    if (bench_flag)
    {
        // criar essa função no arquivo benchmark.c!
        // print_benchmark(&stack, disorder, algo_flag); 
    }

    free_stack(&stack);
    return (0);
}
