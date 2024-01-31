
#include "stack.h"
#include <stdbool.h>

static bool	valid_arg(char *arg)
{
	long long	num;
	int			sign;

	sign = 1;
	if (*arg == '\0')
		return (false);
	if (*arg == '-' || *arg == '+')
	{
		if (*arg == '-')
			sign = -1;
		arg++;
		if (*arg == '\0')
			return (false);
	}
	num = 0;
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (false);
		num = num * 10 + (*arg - '0');
		if (((sign == 1 && num > INT_MAX) || (sign == -1 && - num < INT_MIN)))
			return (false);
		arg++;
	}
	return (true);
}

void	check_duplication(t_table *data, int *numbers, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (numbers[i] == numbers[j])
			{
				free(numbers);
				error(data);
			}
			j++;
		}
		i++;
	}
}

void	random_to_rank(int *numbers, int *rank, int size)
{
	int	i;
	int	j;
	int	count_smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		count_smaller = 0;
		while (j < size)
			if (numbers[j++] <= numbers[i])
				count_smaller++;
		rank[i] = count_smaller;
		i++;
	}
}

void	fill_stack(t_table *data, t_stack *stack, int size, char **arg)
{
	int	*numbers;
	int	i;

	numbers = malloc(sizeof(int) * size);
	if (numbers == NULL)
		error(data);
	i = 0;
	while (arg[i] != NULL)
	{
		if (!valid_arg(arg[i]))
			error(data);
		numbers[i] = ft_atoi(arg[i]);
		i++;
	}
	check_duplication(data, numbers, size);
	random_to_rank(numbers, stack->items, size);
	stack->bottom = size - 1;
	free(numbers);
}
