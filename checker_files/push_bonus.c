/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:41:14 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 04:42:48 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*tmp;

	if (!(*a))
		return ;
	tmp = *a;
	if ((*a)->next != NULL)
	{
		*a = (*a)->next;
		(*a)->prev = NULL;
	}
	else
		*a = NULL;
	if ((*b) != NULL)
	{
		tmp->next = *b;
		(*b)->prev = tmp;
		*b = tmp;
	}
	else
	{
		*b = tmp;
		tmp->next = NULL;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pb\n", 3);
}
