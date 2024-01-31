
#include "stack.h"

static void	rotate(t_stack *stack)
{
	if (is_full(stack))
	{
		stack->bottom = stack->top;
		stack->top = next_down(stack, stack->top);
	}
	else
	{
		stack->bottom = next_down(stack, stack->bottom);
		stack->items[stack->bottom] = stack->items[stack->top];
		stack->items[stack->top] = 0;
		stack->top = next_down(stack, stack->top);
	}
}

void	rotate_a(t_table *data)
{
	rotate(&data->a);
	if (data->writing_mode)
		save_op(data, ra);
}

void	rotate_b(t_table *data)
{
	rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rb);
}

void	rotate_ab(t_table *data)
{
	rotate(&data->a);
	rotate(&data->b);
	if (data->writing_mode)
		save_op(data, rr);
}
