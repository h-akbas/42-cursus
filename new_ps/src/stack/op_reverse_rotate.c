

#include "stack.h"

void	r_rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->top = stack->bottom;
		stack->bottom = next_up(stack, stack->bottom);
	}
	else
	{
		stack->top = next_up(stack, stack->top);
		stack->items[stack->top] = stack->items[stack->bottom];
		stack->items[stack->bottom] = 0;
		stack->bottom = next_up(stack, stack->bottom);
	}
}

void	r_rotate_a(t_table *data)
{
	r_rotate(&data->a);
	if (data->writing_mode)
		save_op(data, rra);
}

void	r_rotate_b(t_table *data)
{
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrb);
}

void	r_rotate_ab(t_table *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rrr);
}
