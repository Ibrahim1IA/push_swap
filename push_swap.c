/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:24:09 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/26 22:41:30 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (verify_args(ac, av))
		free_errors(&a);

	merge_and_init(&a, av + 1);
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
