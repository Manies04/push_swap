/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:59:05 by tiade-al          #+#    #+#             */
/*   Updated: 2024/10/23 01:46:30 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**new_argv;

	a = NULL;
	b = NULL;
	new_argv = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (argc == 2)
	{
		new_argv = ft_split(argv[1], ' ');
		build_stack_a(&a, new_argv, 1);
	}
	else
		build_stack_a(&a, argv + 1, 0);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2 || stack_len(a) == 3)
			sort_small(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
