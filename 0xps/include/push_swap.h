/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alyildiz <alyildiz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 21:47:07 by alyildiz          #+#    #+#             */
/*   Updated: 2023/09/06 17:41:53 by alyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

void				ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack				*ft_lstnew(int n);
int					validate_arg(char **tab);
int					is_sorted(t_stack **stack_a);
long long int		ft_atoll(char *nbr, t_stack **stack_a, char **tab);
int					valid_argument(char *argv);
int					ft_tablen(char **tab);

int					has_doubles(t_stack **stack_a);
int					ft_init(t_stack **stack_a, int argc, char **argv);
int					push_to_stack_a(t_stack **stack_a, char **argv);
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_a, t_stack **stack_b);
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

int					get_index_of_min(t_stack **stack_a);
void				sorting_two_numbers(t_stack **stack_a);
void				sorting_three_numbers(t_stack **stack_a);
int					find_min(t_stack *stack_a);
int					find_max(t_stack *stack_a);
void				choose_algo(t_stack **stack_a, t_stack **stack_b);
void				sorting_five_numbers(t_stack **stack_a, t_stack **stack_b);
int					ft_lstsize(t_stack *lst);
void				pushing_back_to_a(t_stack **stack_a, t_stack **stack_b,
						int size);
void				sorting_to_hundred(t_stack **stack_a, t_stack **stack_b,
						int size);
void				sorting(t_stack **stack_a, t_stack **stack_b, int size);
void				free_all(t_stack **stack_a, t_stack **stack_b, int *tab);
void				free_s(t_stack **stack);
void				sort_int_tab(int *tab, int size);
int					*creating_tab(t_stack **stack_a);
int					rb_or_rrb(t_stack **stack_b, int size);

#endif