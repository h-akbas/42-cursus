/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 06:16:23 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 19:26:15 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	instructions(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		ft_sa(stack_a);
	if (ft_strcmp(str, "sb\n") == 0)
		ft_sb(stack_b);
	if (ft_strcmp(str, "ss\n") == 0)
		ft_ss(stack_a, stack_b);
	if (ft_strcmp(str, "ra\n") == 0)
		ft_ra(stack_a);
	if (ft_strcmp(str, "rb\n") == 0)
		ft_rb(stack_b);
	if (ft_strcmp(str, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	if (ft_strcmp(str, "rra\n") == 0)
		ft_rra(stack_a);
	if (ft_strcmp(str, "rrb\n") == 0)
		ft_rrb(stack_b);
	if (ft_strcmp(str, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	if (ft_strcmp(str, "pa\n") == 0)
		ft_pa(stack_a, stack_b);
	if (ft_strcmp(str, "pb\n") == 0)
		ft_pb(stack_a, stack_b);
}

int	check_instructions(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (0);
	if (ft_strcmp(str, "sb\n") == 0)
		return (0);
	if (ft_strcmp(str, "ss\n") == 0)
		return (0);
	if (ft_strcmp(str, "ra\n") == 0)
		return (0);
	if (ft_strcmp(str, "rb\n") == 0)
		return (0);
	if (ft_strcmp(str, "rr\n") == 0)
		return (0);
	if (ft_strcmp(str, "rra\n") == 0)
		return (0);
	if (ft_strcmp(str, "rrb\n") == 0)
		return (0);
	if (ft_strcmp(str, "rrr\n") == 0)
		return (0);
	if (ft_strcmp(str, "pa\n") == 0)
		return (0);
	if (ft_strcmp(str, "pb\n") == 0)
		return (0);
	return (1);
}

int	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (check_instructions(str) != 0)
			return (free(str), free_s(stack_a), free_s(stack_b), write(2,
					"Error\n", 6), exit(1), 1);
		instructions(stack_a, stack_b, str);
		if (str)
			free(str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	if (ft_init(&stack_a, argc, argv) == 1)
		return (1);
	if (checker(&stack_a, &stack_b))
	{
		if (!(stack_b) && is_sorted(&stack_a))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free_s(&stack_a);
	free_s(&stack_b);
}
