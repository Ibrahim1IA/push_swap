/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:45:50 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/27 17:20:54 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(int n, int array[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

void	bring_on_top(t_stack_node **stack, t_stack_node *top, bool i)
{
	while (*stack != top)
	{
		if (i)
		{
			if (top->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else
		{
			if (top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

void	init_sort_index(t_stack_node *a)
{
	int	*array;
	int	len;

	len = stack_lenght(a);
	array = get_sorted_stack_in_array(a);
	if (!array)
		return ;
	while (a)
	{
		a->index[0] = find_position(a->nbr, array, len);
		a = a->next;
	}
	free(array);
}

void	free_split_args(char **arr)
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

void	parste_and_init(char *str, t_stack_node **a)
{
	char	**args;

	args = ft_split(str, ' ');
	free(str);
	init_stack_a(a, args);
	free_split_args(args);
}
