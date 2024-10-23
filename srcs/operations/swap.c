/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:08:01 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/22 22:50:07 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/**@brief Swap the first 2 elements at the top of the stack.
*Do nothing if there is only one or no elements.
*@param *head: The stack to swap.
*@return void.
 */
void	swap(t_stack *head)
{
	int	tmp;

	if (head && head->next)
	{
		tmp = head->value;
		head->value = head->next->value;
		head->next->value = tmp;
	}
}

void	sa(t_stack *a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
