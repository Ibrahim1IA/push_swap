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


static void    verif_min_on_top(t_stack_node **a)
{
    t_stack_node *min;

    min = find_min(*a);
    while ((*a)->nbr != min)
    {
        if ((*a)->above_median)
            ra(a, false);
        else
            rra(a, false);
    }
}
static void    rotate_all(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while (*b != cheapest->target_node && *a != cheapest)
        rr(a, b, false);
    refresh_index(*a);
    refresh_index(*b);
}

static void    reverse_rotate_all(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while (*b != cheapest->target_node && *a != cheapest)
        rrr(a, b, false);
    refresh_index(*a);
    refresh_index(*b);
}

static void    push_cheapest_to_b(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest;

    cheapest = get_cheapest(*a);
    if (cheapest->above_median && cheapest->target_node->above_median)
        rotate_all(a, b, cheapest);
    else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
        reverse_rotate_all(a, b, cheapest);
    bring_on_top(a, cheapest, false);
    bring_on_top(b, cheapest->target_node, true);
    pb(a, b, false);
}

void    sort_stack(t_stack_node **a, t_stack_node **b)
{
    int len;

    len = stack_lenght(*a);
    if (len-- > 3 && !stack_sorted(*a))
        pa(a, b, false);
    if (len-- > 3 && !stack_sorted(*a))
        pa(a, b, false);
    while (len-- > 3 && !stack_sorted(*a))
    {
        init_a(*a, *b);
        push_cheapest_to_b(a, b);
    }
    three_sort(a);
    while (*b)
    {
        init_b(*a, *b);
        bring_on_top(a, (*b)->target_node, false);
        pa(a, b, false);
    }
    refresh_index(*a);
    verif_top_node(a);
}
