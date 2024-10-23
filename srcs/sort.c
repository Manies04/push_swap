/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:49:10 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 18:53:01 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*@brief Sorts the stacks using the push_swap algorithm
 *@param **a: The stack to sort
 *@param **b: The second stack to use for sorting
 *@return void
 */
void	sort_stacks(t_stack **a, t_stack **b)
{
	int	len_stack_a;

	len_stack_a = stack_len(*a);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	if (len_stack_a-- > 3 && !stack_sorted(*a))
		pb(b, a);
	while (len_stack_a-- > 3 && !stack_sorted(*a))
	{
		a_nodes_init(*a, *b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		b_nodes_init(*a, *b);
		b_to_a(a, b);
	}
	current_index(*a);
	lowest_num_first(a);
}

/*@brief Initializes the nodes in stack b
 *@param *a: Stack
 *@param *b: Stack
 */
void	b_nodes_init(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	b_target(a, b);
}

/*@brief Sets the target node for each node in stack b
 *@param *a: Stack
 *@param *b: Stack
 */
void	b_target(t_stack *a, t_stack *b)
{
	t_stack		*status_a;
	t_stack		*target_node;
	long int	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		status_a = a;
		while (status_a)
		{
			if (status_a->value > b->value
				&& status_a->value < best_match_index)
			{
				best_match_index = status_a->value;
				target_node = status_a;
			}
			status_a = status_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

/*@brief Pushes `b` nodes to stack `a`
 *@param **a: Stack to push to
 *@param **b: Stack to push from
 */
void	b_to_a(t_stack **a, t_stack **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

/*@brief Get the smallest element to the top of the stack by rotating the 
*stack in the most efficient direction.
 *@param **a: The stack to sort
 *@return void
 */
void	lowest_num_first(t_stack **a)
{
	while ((*a)->value != find_min(*a)->value)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
