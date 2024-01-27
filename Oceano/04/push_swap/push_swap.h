/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakbas <hakbas@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:23:44 by hakbas            #+#    #+#             */
/*   Updated: 2024/01/27 18:26:26 by hakbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>

typedef struct s_stack
{
	int					value;
	int					current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack		*target_node;
	struct s_stack		*next;
	struct s_stack		*prev;
}				t_stack;	

//*** Handle input ./push_swap "1 -42 1337" ***
char			**ft_split(char const *s, char c);

//*** Handle errors-free ***
void			free_args(char **argv);
void			error_free(t_stack **a, char **argv, bool flag_argc_2);
void			free_stack(t_stack **stack);
int				error_repetition(t_stack *a, int nbr);
int				error_syntax(char *str_nbr);

//*** Stack creation ***
void			stack_init(t_stack **a, char **argv, bool flag_argc_2);
void			init_nodes(t_stack *a, t_stack *b);
void			set_current_position(t_stack *stack);
void			set_price(t_stack *a, t_stack *b);
void			set_cheapest(t_stack *b);

//*** linked list utils ***
void			append_node(t_stack **stack, int nbr);
t_stack			*find_last_node(t_stack *head);
t_stack			*find_smallest(t_stack *stack);
t_stack			*return_cheapest(t_stack *stack);
bool			stack_sorted(t_stack *stack);
int				stack_len(t_stack *stack);
void			finish_rotation(t_stack **s, t_stack *n, char c);

//*** Algorithms ***
void			tiny_sort(t_stack **a);
void			handle_five(t_stack **a, t_stack **b);
void			push_swap(t_stack **a, t_stack **b);

//*** Commands ***
void			sa(t_stack **a, bool checker);
void			sb(t_stack **b, bool checker);
void			ss(t_stack **a, t_stack **b, bool checker);
void			ra(t_stack **a, bool checker);
void			rb(t_stack **b, bool checker);
void			rr(t_stack **a, t_stack **b, bool checker);
void			rra(t_stack **a, bool checker);
void			rrb(t_stack **b, bool checker);
void			rrr(t_stack **a, t_stack **b, bool checker);
void			pa(t_stack **a, t_stack **b, bool checker);
void			pb(t_stack **b, t_stack **a, bool checker);

#endif
