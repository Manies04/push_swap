/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 20:03:04 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 22:50:04 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* @brief Shift up all elements of the stack by 1.
*The first element becomes the last one.
*@param **top_node: The stack to rotate
*@return void
 */
void	rotate(t_stack **top_node)
{
	t_stack	*last_node;
	t_stack	*new_top;

	if (!(*top_node) || !(*top_node)->next)
		return ;
	last_node = last_node_finder(*top_node);
	new_top = (*top_node)->next;
	last_node->next = *top_node;
	(*top_node)->prev = last_node;
	(*top_node)->next = NULL;
	*top_node = new_top;
	new_top->prev = NULL;
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
