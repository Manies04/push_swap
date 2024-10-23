/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:57:23 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/23 01:49:32 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**@brief Sorts three numbers in the stack
 *@param **a: The stack to sort
 *@return void
 */
void	sort_three(t_stack **a)
{
	t_stack	*biggest_one;

	biggest_one = biggest_one_finder(*a);
	if (biggest_one == *a)
		ra(a);
	else if ((*a)->next == biggest_one)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(*a);
}

/**@brief The append function, appends a new node to the bottom of the stack.
 *@param **stack: The stack to append to
 *@param num: The value of the new node
 *@return void. After running enough times the stack(a) will be built
 */
void	append(t_stack **stack, int num)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	new->value = num;
	new->next = NULL;
	if (!*stack)
	{
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
		new->prev = last;
	}
}

/**@brief Builds the stack a.
 *@param **a: The stack to build
 *@param **argv: The arguments to build the stack with
 *@return void.
 */
void	build_stack_a(t_stack **a, char **argv, int to_free)
{
	long	num;
	int		i;

	i = -1;
	while (argv[++i])
	{
		if (syntax_check(argv[i]) == 1)
		{
			if (to_free)
				free_argv(argv);
			error_handler(a);
		}
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN
			|| duplicate_check(*a, (int)num) == 1)
		{
			if (to_free)
				free_argv(argv);
			error_handler(a);
		}
		append(a, (int)num);
	}
	if (to_free)
		free_argv(argv);
}

void	sort_small(t_stack **a)
{
	if (stack_len(*a) == 2)
		sa(*a);
	else if (stack_len(*a) == 3)
		sort_three(a);
}
