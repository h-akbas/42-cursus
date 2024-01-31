
#include "stack.h"

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->items[next_down(stack, stack->top)] == 0)
		return ;
	tmp = stack->items[next_down(stack, stack->top)];
	stack->items[next_down(stack, stack->top)] = stack->items[stack->top];
	stack->items[stack->top] = tmp;
}

void	swap_a(t_table *data)
{
	swap(&data->a);
	if (data->writing_mode)
		save_op(data, sa);
}

void	swap_b(t_table *data)
{
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, sb);
}

void	swap_ab(t_table *data)
{
	swap(&data->a);
	swap(&data->b);
	if (data->writing_mode)
		save_op(data, ss);
}
