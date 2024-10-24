/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:33:55 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/24 14:30:37 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_handler(t_stack **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}

/**@brief Checks if a number is duplicated in the stack
 *@param a: The stack to check
 *@param num: The number to check
 *@return 1 if the number is in the stack (duplicated), 0 if it is not
 */
int	duplicate_check(t_stack *a, int num)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == num)
			return (1);
		a = a->next;
	}
	return (0);
}

/**@brief The syntax_check function, checks if a string is a valid number
 *@param str: The string to check
 *@return 0 if the string is a valid number, 1 if it is not
 */
int	syntax_check(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}
