/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:01:00 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 22:04:32 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*@brief Finds the smallest node in the stack
 *@param stack: The stack to search
 *@return The smallest node in the stack
 */
t_stack	*find_min(t_stack *stack)
{
	t_stack	*min_node;
	long	min_value;

	min_value = LONG_MAX;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

/*@brief Finds the biggest node in the stack
 *@param stack: The stack to search
 *@return The biggest node in the stack
 */
t_stack	*biggest_one_finder(t_stack *stack)
{
	long int	max;
	t_stack		*biggest;

	max = LONG_MIN;
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->value > max)
		{
			biggest = stack;
			max = stack->value;
		}
		stack = stack->next;
	}
	return (biggest);
}

/*@brief Finds the cheapest node in the stack
 *@param stack: The stack to search
 *@return The cheapest node in the stack
 */
t_stack	*find_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

/*@brief Finds the last node in the stack
 *@param top_node: The stack to search
 *@return The last node in the stack
 */
t_stack	*last_node_finder(t_stack *top_node)
{
	while (top_node->next)
		top_node = top_node->next;
	return (top_node);
}
