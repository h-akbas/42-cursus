
#include "stack.h"

int	next_up(t_stack *stack, int index)
{
	if (current_size(stack) == 0)
		return (index);
	if (index == 0)
		return (stack->size - 1);
	else
		return (index - 1);
}

int	next_down(t_stack *stack, int index)
{
	if (current_size(stack) == 0)
		return (index);
	if (index == stack->size - 1)
		return (0);
	else
		return (index + 1);
}

int	value(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (--n > 0)
		i = next_down(stack, i);
	return (stack->items[i]);
}

int	current_size(t_stack *stack)
{
	if (stack->top == stack->bottom && stack->items[stack->top] == 0)
		return (0);
	if (stack->top > stack->bottom)
		return ((stack->size - stack->top) + (stack->bottom + 1));
	else
		return (stack->bottom - stack->top + 1);
}

bool	is_full(t_stack *stack)
{
	return (stack->size == current_size(stack));
}
