
#include "stack.h"


static	void	init_stack(t_table *data, t_stack *stack, int size)
{
	stack->items = malloc(sizeof(int) * size);
	if (!stack->items)
		error(data);
	stack->top = 0;
	stack->bottom = 0;
	stack->size = size;
	ft_bzero(stack->items, sizeof(int) * size);
}

void	init_data(t_table *data, int argc, char **argv, bool writing_mode)
{
	--argc;
	init_stack(data, &data->a, argc);
	init_stack(data, &data->b, argc);
	fill_stack(data, &data->a, argc, ++argv);
	data->writing_mode = writing_mode;
	data->op_list = NULL;
}


bool	is_sorted(t_table *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank <= data->a.size)
	{
		if (data->a.items[i] != rank)
			return (false);
		rank++;
		i = next_down(&data->a, i);
	}
	return (true);
}


void	error(t_table *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	free_data(t_table *data)
{
	if (data->a.items)
		free(data->a.items);
	if (data->b.items)
		free(data->b.items);
	if (data->op_list)
		ft_lstclear(&data->op_list, NULL);
}
