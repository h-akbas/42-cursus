
#include "push_swap.h"

int ft_count_args(char **args)
{
	int count;

	count = 0;
	while(*args)
	{
		count++;
		args++;
	}
	return (count + 1);
}

int	main(int argc, char *argv[])
{
	t_table	data;
	char	**args;
	int		argc_n;
	
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		argc_n = ft_count_args(args);
		if (args != NULL && *args != NULL)
		{
			init_data(&data, argc_n, args, true);
			free(args);
		}
	}
	else
		init_data(&data, argc, argv, true);
	sort(&data);
	print_operations(data.op_list);
	free_data(&data);
	exit(EXIT_SUCCESS);
}
