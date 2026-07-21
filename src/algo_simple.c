#include "push_swap.h"

static void	process_a(t_stack *stack, int sorted)
{
	while (sorted)
	{
		if (stack->a->value > stack->a->next->value)
			sa(stack);
		pb(stack);
		sorted--;
	}
}
static void	process_b(t_stack *stack, int sorted)
{
	while (sorted < stack->size_b - 1)
	{
		if (stack->b->value < stack->b->next->value)
			sb(stack);
		pa(stack);
	}
}

static void	restore_stack(t_stack *stack)
{
	while (stack->size_b > 0)
		pa(stack);
}
void	algo_adaptive(t_stack *stack)
{
	int	sorted_tail;
	int	sorted_head;

	sorted_head = 0;
	sorted_tail = stack->size_a - 1;
	while (sorted_head < sorted_tail && is_sorted(stack->a) == 0)
	{
		process_a(stack, sorted_tail);
		process_b(stack, sorted_head);
		sorted_head++;
		sorted_tail--;
	}
	restore_stack(stack);
	print_list(stack->a);
}
