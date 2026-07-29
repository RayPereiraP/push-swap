/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 12:38:59 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/23 12:38:59 by wgolbert         ###   ########.fr       */
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
}					t_stack;

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
}					t_flags;
typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	t_flags			flags;
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
int					*index_array(int *stack, int size);
t_push_swap			*init_push_swap(int *array, int size, int bench, char flag);
void				free_stack(t_stack *stack);
void				free_push_swap(t_push_swap *ps);
int					ft_sqrt(int nb);
int					is_sorted(t_stack *stack);
#endif