
#include "stack.h"

static void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (is_full(dest))
		return ;
	dest_i = next_up(dest, dest->top);
	dest->items[dest_i] = src->items[src->top];
	dest->top = dest_i;
	src->items[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_table *data)
{
	push(&data->b, &data->a);
	if (data->writing_mode)
		save_op(data, pa);
}

void	push_b(t_table *data)
{
	push(&data->a, &data->b);
	if (data->writing_mode)
		save_op(data, pb);
}
