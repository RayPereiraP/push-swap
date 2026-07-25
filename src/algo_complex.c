// radix sort
#include "push_swap.h"

// quantidade de bits necessária pra representar os índices (0 a size-1)
static int	get_max_bits(t_stack *stack)
{
	int	max_index;
	int	max_bits;

	max_index = stack->size - 1;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

// processa um bit específico do índice de cada elemento:
// se o bit for 1, manda pra fila (rotaciona a); se for 0, empilha em b
static void	process_bits(t_push_swap *ps, int bit_pos)
{
	int	j;
	int	size;

	j = 0;
	size = ps->a->size;
	while (j < size)
	{
		if (((ps->a->head->index >> bit_pos) & 1) == 1)
			ra(ps);
		else
			pb(ps);
		j++;
	}
	while (ps->b->size > 0)
		pa(ps);
}

void	algo_complex(t_push_swap *ps)
{
	int	i;
	int	max_bits;

	max_bits = get_max_bits(ps->a);
	i = 0;
	while (i < max_bits)
	{
		process_bits(ps, i);
		i++;
	}
}
