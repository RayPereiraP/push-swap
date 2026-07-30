/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgolbert <wgolbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 11:15:21 by wgolbert          #+#    #+#             */
/*   Updated: 2026/07/20 11:15:21 by wgolbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	algo_adaptive(t_push_swap *ps)
{
	double	disorder;

	disorder = compute_disorder(ps->a);
	if (disorder < 0.2)
		algo_simple(ps);
	else if (disorder < 0.5)
		algo_medium(ps);
	else
		algo_complex(ps);
}
