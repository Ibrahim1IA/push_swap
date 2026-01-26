/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 23:10:49 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/10 18:32:24 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_lenght(t_stack_node *s)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (s)
	{
		s = s->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last(t_stack_node *s)
{
	if (!s)
		return (NULL);
	while (s->next)
		s = s->next;
	return (s);
}

bool	stack_sorted(t_stack_node *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->nbr > s->next->nbr)
			return (false);
		s = s->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *s)
{
	long			min;
	t_stack_node	*n_min;

	min = LONG_MAX;
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->nbr < min)
		{
			min = s->nbr;
			n_min = s;
		}
		s = s->next;
	}
	return (n_min);
}

t_stack_node	*find_max(t_stack_node *s)
{
	t_stack_node	*n_max;
	long			max;

	max = LONG_MIN;
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->nbr > max)
		{
			max = s->nbr;
			n_max = s;
		}
		s = s->next;
	}
	return (n_max);
}
