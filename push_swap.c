/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:24:09 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/28 02:25:20 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
static void	free_errors_args(char **str)
{
	if (str)
		free(*str);
	write(2, "Error\n", 6);
	exit(1);
}
void print_stack(t_stack_node *a)
{
	printf(" ");
	while (a)
	{
		printf("%d ", a->nbr);
		a = a->next;
	}
}
int	main(int ac, char **av)
{
	t_stack_node *a;
    t_stack_node *b;
    char *args;

    a = NULL;
    b = NULL;
    args = NULL;
	if (ac == 1)
		return (0);
	if (verify_args(&args, av + 1))
		free_errors_args(&args);
	parste_and_init(args, &a);
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
