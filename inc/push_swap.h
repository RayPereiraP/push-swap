/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:00:04 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/19 17:22:59 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>

typedef struct s_list
{
	int				value;
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

typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	t_benchmark		benchmark;
}					t_push_swap;

void				sa(t_push_swap *stack);
void				sb(t_push_swap *stack);
void				ss(t_push_swap *stack);
void				pa(t_push_swap *stack);
void				pb(t_push_swap *stack);
void				ra(t_push_swap *stack);
void				rb(t_push_swap *stack);
void				rr(t_push_swap *stack);
void				rra(t_push_swap *stack);
void				rrb(t_push_swap *stack);
void				rrr(t_push_swap *stack);
double				compute_disorder(t_stack *stack);

/*
int					init_push_swap(t_push_swap *ps, int *array, int size, int *flags); //Inicialização
int					parse_arguments(int argc, char **argv, int **array, int *size); //Parsing e flags
void				print_benchmark(t_push_swap *ps, double initial_disorder, int *flags); //Benchmark 
void				free_all(t_push_swap *ps); //Memória
int					free_and_exit(t_push_swap *ps, int status); //Memória
int					ft_strcmp(const char *s1, const char *s2); //Utils
*/

#endif
