/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 21:14:26 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/15 17:54:46 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	verif_min_on_top(t_stack_node **a)
{
	int	len;

	len = stack_lenght(*a) / 2;
	while ((*a)->index[0] != 0)
	{
		if ((*a)->index[0] > len)
			ra(a, false);
		else
			rra(a, false);
	}
	refresh_index(*a);
}

static void	rotate_all(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b, false);
	refresh_index(*a);
	refresh_index(*b);
}

static void	reverse_rotate_all(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b, false);
	refresh_index(*a);
	refresh_index(*b);
}

static void	push_cheapest_to_a(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_all(a, b, cheapest);
	else if (!(cheapest->above_median)
		&& !(cheapest->target_node->above_median))
		reverse_rotate_all(a, b, cheapest);
	bring_on_top(a, cheapest, false);
	bring_on_top(b, cheapest->target_node, true);
	pa(b, a, false);
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	int	len;

	len = stack_lenght(*a);
	pb(a, b, 0);
	--len;
	while (len > 3 && !stack_sorted(*a))
	{
		pb(a, b, 0);
		if ((*b)->index[0] < len / 2)
			rb(b, 0);
		len--;
	}
	if (len == 3)
		three_sort(a);
	while (*b)
	{
		init_a(*b, *a);
		push_cheapest_to_a(b, a);
	}
	verif_min_on_top(a);
}
