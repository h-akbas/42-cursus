/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:34:15 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/24 21:52:10 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

static bool	check_argv_validity(char *argv);
static void check_duplicate(t_data *data, int *numbers, int size);
static void assign_rank(int *arr, int *rank, int size); 

void    fill_stack(t_data *data, t_stack *stack, int size, char **argv)
{
    int     *numbers;
    int     i;
    
    numbers = (int *)malloc(sizeof(int) * size);
    if (!numbers)
        put_error(data);
    i = 0;
    while (argv[i])
    {
        if (!check_argv_validity(argv[i]))
            put_error(data);
        numbers[i] = ft_atoi(argv[i]);
        i++;
    }
    check_duplicate(data, numbers, size);
    assign_rank(numbers, stack->arr, size);
    stack->bottom = size - 1;
    free(numbers);
}
static bool	check_argv_validity(char *argv)
{
    long long	number;
    int			sign;
    
    sign = 1;
    if (*argv == '\0')
        return (false);
    if (*argv == '-' || *argv == '+')
    {
        if (*argv == '-')
            sign = -1;
        argv++;
        if (*argv == '\0')
            return (false);
    }
    number = 0;
    while (*argv)
    {
        if (!is_digit(*argv))
            return (false);
        number = number * 10 + (*argv - '0');
        if ((sign == 1 && number > INT_MAX) || (sign == -1 && number < INT_MIN))
            return (false);
        argv++;
    }
}
void	check_duplicate(t_data *data, int *numbers, int size)
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
				put_error(data);
			}
			j++;
		}
		i++;
	}
}

void    assign_rank(int *arr, int *rank, int size)
{
    int i;
    int j;
    int n;
    
    i = 0;
    while (i < size)
    {
        j = 0;
        n = 0;
        while (j < size)
            if (arr[j++] <= arr[i])
                n++;
        rank[i] = n;
        i++;
    }
}