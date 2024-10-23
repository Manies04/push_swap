/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 00:13:46 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 22:05:56 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**@brief This arranges the stacks so that the cheapest node is at the top 
 * and pushes it to the other stack
 * @param **a: The stack to push from
 * @param **b: The stack to push to
 * @return: void
 */
void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = find_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

/**@brief This arranges the stacks so that the cheapest node is at the top 
 * ready to be pushed to the other stack
 * @param **stack: The stack to push from
 * @param *top_node: The node to push
 * @param stack_name: The name of the stack
 * @return: void
 */
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/**@brief Rotates both the top `a` and `b` nodes to the bottom of their stacks,
 * if it's the cheapest move.
 * @param **a: The stack to rotate
 * @param **b: The stack to rotate
 * @param *cheapest_node: The cheapest node
 * @return: void
 */
void	rotate_both(t_stack **a,
						t_stack **b,
						t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

/**@brief Reverse rotates both the top `a` and `b` nodes to the bottom of their
 *  stacks, if it's the cheapest move.
 * @param **a: The stack to rotate
 * @param **b: The stack to rotate
 * @param *cheapest_node: The cheapest node
 * @return: void
 */
void	rev_rotate_both(t_stack **a,
								t_stack **b,
								t_stack *cheapest_node)
{
	while (*b != cheapest_node->target_node
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}
