/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:47:19 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/23 01:49:49 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**@brief Gets the length of the stack
 *@param a: The stack to measure
 *@return The length of the stack
 */
int	stack_len(t_stack *a)
{
	int	len;

	if (!a)
		return (0);
	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

/**@brief Checks if the stack is sorted
 *@param a: The stack to check
 *@return 1 if the stack is sorted, 0 if it is not
 */
int	stack_sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

/**@brief Frees the stack
 *@param stack: The stack to free
 *@return void
 */
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	exit(0);
}

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

/**@brief Converts a string to a long int
 *@param str: The string to convert
 *@return The converted long int
 */
long int	ft_atol(char *str)
{
	long int	res;
	int			sign;
	int			i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
