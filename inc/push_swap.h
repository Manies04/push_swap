/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:59:10 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/23 01:28:39 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				above_median;
	int				push_cost;
	int				cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}				t_stack;

//swap.c
void		swap(t_stack *head);
void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
//push.c
void		push(t_stack **dst, t_stack **src);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **b, t_stack **a);
//rotate.c
void		rotate(t_stack **top_node);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
//reverse_rotate.c
void		reverse_rotate(t_stack **top_node);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
//error_management.c
void		error_handler(t_stack **a);
int			duplicate_check(t_stack *a, int num);
int			syntax_check(char *str);
//helpers.c
int			stack_len(t_stack *a);
int			stack_sorted(t_stack *a);
void		free_stack(t_stack **stack);
void		free_argv(char **argv);
long int	ft_atol(char *str);
//finders.c
t_stack		*find_min(t_stack *stack);
t_stack		*biggest_one_finder(t_stack *stack);
t_stack		*find_cheapest(t_stack *stack);
t_stack		*last_node_finder(t_stack *top_node);
//init_a_nodes.c
void		a_nodes_init(t_stack *a, t_stack *b);
void		current_index(t_stack *stack);
void		target_a(t_stack *a, t_stack *b);
void		push_cost_a(t_stack *a, t_stack *b);
void		set_cheapest(t_stack *stack);
//sort.c
void		sort_stacks(t_stack **a, t_stack **b);
void		b_nodes_init(t_stack *a, t_stack *b);
void		b_target(t_stack *a, t_stack *b);
void		b_to_a(t_stack **a, t_stack **b);
void		lowest_num_first(t_stack **a);
//sorting_func.c
void		sort_three(t_stack **a);
void		append(t_stack **stack, int num);
void		build_stack_a(t_stack **a, char **argv, int to_free);
void		sort_small(t_stack **a);
//stack_sorting.c
void		a_to_b(t_stack **a, t_stack **b);
void		prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void		rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void		rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

#endif