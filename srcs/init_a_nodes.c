/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a_nodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 19:25:33 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 22:49:00 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**@brief This function initializes the nodes in the stack by setting the index,
 * target node, push cost and a flag for the cheapest node in stack a.
 * @param *a: The stack to initialize
 * @param *b: The stack to compare to
 * @return: void
 */
void	a_nodes_init(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	target_a(a, b);
	push_cost_a(a, b);
	set_cheapest(a);
}

/**@brief This function sets the index for each node in the stack and sets the
 * above_median flag to 1 if the node is above the median index, 0 otherwise.
 * @param *stack: The stack to set the index for
 * @return: void
 */
void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

/**@brief The function finds the closest smaller node from stack b, for each 
 * node in stack a. If no smaller node is found, the node with the maximum 
 * value in stack b is assigned as the target.
 */
void	target_a(t_stack *a, t_stack *b)
{
	t_stack		*status_b;
	t_stack		*the_target_on_b;
	long int	closest_index;

	while (a)
	{
		closest_index = LONG_MIN;
		status_b = b;
		while (status_b)
		{
			if (status_b->value < a->value && status_b->value > closest_index)
			{
				closest_index = status_b->value;
				the_target_on_b = status_b;
			}
			status_b = status_b->next;
		}
		if (closest_index == LONG_MIN)
			a->target_node = biggest_one_finder(b);
		else
			a->target_node = the_target_on_b;
		a = a->next;
	}
}

/**@brief Calculates the cost of pushing each node from stack a to 
 * its target position in stack b.
 * @param *a: The stack to push from
 * @param *b: The stack to push to
 * @return: void
 */
void	push_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

/**@brief Sets the cheapest flag to 1 for the node with the smallest push cost.
 * @param *stack: The stack to set the cheapest flag for
 * @return: void
 */
void	set_cheapest(t_stack *stack)
{
	t_stack		*cheapest_node;
	long int	smallest_rv;

	if (!stack)
		return ;
	smallest_rv = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < smallest_rv)
		{
			cheapest_node = stack;
			smallest_rv = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
