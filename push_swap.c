/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:24:09 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 04:44:48 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_errors_args(char **str)
{
	if (str)
		free(*str);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*args;

	a = NULL;
	b = NULL;
	args = NULL;
	if (ac == 1)
		return (0);
	if (verify_args(&args, av + 1))
		free_errors_args(&args);
	if (!parste_and_init(args, &a))
		free_errors_args(&args);
	free(args);
	if (!stack_sorted(a))
	{
		if (stack_lenght(a) == 2)
			sa(&a, false);
		else if (stack_lenght(a) == 3)
			three_sort(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
	return (0);
}
