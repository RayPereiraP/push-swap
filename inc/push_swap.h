/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:06:50 by rayperei          #+#    #+#             */
/*   Updated: 2026/06/28 21:06:51 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	t_list			*head;
	t_list			*tail;
	int				size;
} 					t_stack;

typedef struct s_benchmark
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_benchmark;

typedef struct s_flags
{
	char			flag;
	int				bench;
} 					t_flags;

typedef struct s_push_swap
{
	t_list          *a;
	int             size_a;
	t_list          *b;
	int             size_b;
	t_benchmark     benchmark;
}                   t_stack;

// Operações de Swap
void    sa(t_stack *stack);
void    sb(t_stack *stack);
void    ss(t_stack *stack);

// Operações de Push
void    pa(t_stack *stack);
void    pb(t_stack *stack);

// Operações de Rotate
void    ra(t_stack *stack);
void    rb(t_stack *stack);
void    rr(t_stack *stack);

// Operações de Reverse Rotate
void    rra(t_stack *stack);
void    rrb(t_stack *stack);
void    rrr(t_stack *stack);

// Métrica de Desordem
double  compute_disorder(t_stack *stack);

// Parser e Tratamento de Erros
int     parse_arguments(int argc, char **argv, t_stack *stack);
int     is_valid_number(char *str);
int     has_duplicates(t_stack *stack);
void    free_stack(t_stack *stack); // Essencial para limpar a memória se der erro!

// Algoritmos de Ordenação
void    algo_simple(t_stack *stack);
void    algo_complex(t_stack *stack);
void    algo_medium(t_stack *stack);
void    algo_adaptive(t_stack *stack);

#endif