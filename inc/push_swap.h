/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 21:06:50 by rayperei          #+#    #+#             */
/*   Updated: 2026/06/28 21:06:51 by rayperei         ###   ########.fr       */
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
typedef struct s_push_swap
{
	t_stack			*a;
	t_stack			*b;
	t_benchmark		benchmark;
}					t_push_swap;

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

void				sa(t_push_swap *stack);
void				sb(t_push_swap *stack);
void				ss(t_push_swap *stack);
void				pa(t_push_swap *stack);
void				pb(t_push_swap *stack);
void				ra(t_push_swap *stack);
void				rb(t_push_swap *stack);
void				rr(t_push_swap);
void				rra(t_push_swap *stack);
void				rrb(t_push_swap *stack);
void				rrr(t_push_swap *stack);
double				compute_disorder(t_stack *stack);

#endif