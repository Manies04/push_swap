/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 23:57:14 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 22:49:57 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*@brief  Shifts down all elements of the stack by 1.
*The last element becomes the first one.
 *@param **top_node: The stack to rotate
 *@return void
 */
void	reverse_rotate(t_stack **top_node)
{
	t_stack	*new_top;

	if (!(*top_node) || !(*top_node)->next)
		return ;
	new_top = last_node_finder(*top_node);
	new_top->prev->next = NULL;
	new_top->next = *top_node;
	new_top->prev = NULL;
	*top_node = new_top;
	new_top->next->prev = new_top;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
