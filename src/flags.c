/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayperei <rayaryray14@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:34:26 by rayperei          #+#    #+#             */
/*   Updated: 2026/07/23 14:34:35 by rayperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	handle_flags(int argc, char **argv, int *i, int *flags)
{
	while (*i < argc && argv[*i][0] == '-' && argv[*i][1] == '-')
	{
		if (ft_strcmp(argv[*i], "--simple") == 0)
			flags[0] = 1;
		else if (ft_strcmp(argv[*i], "--medium") == 0)
			flags[0] = 2;
		else if (ft_strcmp(argv[*i], "--complex") == 0)
			flags[0] = 3;
		else if (ft_strcmp(argv[*i], "--adaptive") == 0)
			flags[0] = 0;
		else if (ft_strcmp(argv[*i], "--bench") == 0)
			flags[1] = 1;
		else
			break ;
		(*i)++;
	}
	return (0);
}
