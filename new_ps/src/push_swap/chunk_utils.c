

#include "push_swap.h"

int	chunk_value(t_table *data, t_chunk *chunk, int n)
{
	enum e_loc	loc;
	t_stack		*stack;
	int			i;

	loc = chunk->loc;
	stack = loc_to_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = stack->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = stack->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = next_down(stack, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(stack, i);
	return (stack->items[i]);
}

int	chunk_max_value(t_table *data, t_chunk *chunk)
{
	t_stack	*stack;
	int		size;
	int		max_value;
	int		i;

	stack = loc_to_stack(data, chunk->loc);
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stack->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = stack->bottom;
	while (size--)
	{
		if (stack->items[i] > max_value)
			max_value = stack->items[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(stack, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(stack, i);
	}
	return (max_value);
}

t_stack	*loc_to_stack(t_table *data, enum e_loc loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}
