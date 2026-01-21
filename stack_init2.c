/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:45:50 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/21 17:55:35 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_position(int n, int array[])
{
	int	i;

	i = 0;
	while (array[i])
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

void    init_sort_index(t_stack_node *a)
{
    int     *array;

    array = get_sorted_stack_in_array(a);
	if (!array)
		return ;
	while (a)
	{
		a->index[0] = find_position(a->nbr, array);
		a = a->next;
	}
	free(array);
}

int	error_syntax(char *str_n)
{
	if (!(*str_n == '+'
			|| *str_n == '-'
			|| (*str_n >= '0' && *str_n <= '9'))) 
		return (1);
	if ((*str_n == '+'
			|| *str_n == '-')
		&& !(str_n[1] >= '0' && str_n[1] <= '9'))
	while (*++str_n) 
	{
		if (!(*str_n >= '0' && *str_n <= '9')) 
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *a, int n)
{
	if (!a) 
		return (0);
	while (a) 
	{
		if (a->nbr == n) 
			return (1);
		a = a->next; 
	}
	return (0);
}