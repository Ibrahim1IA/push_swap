/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:24:09 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/10 19:33:48 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	parste_and_init(char *str, t_stack_node **a)
{
	char	**args;

	args = ft_split(str, ' ');
	init_stack_a(a, args);
	free_all(args);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		parste_and_init(av[1], &a);
	else
		init_stack_a(&a, av + 1);
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
	return (1);
}
