/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:54:51 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/16 03:08:27 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void refresh_index(t_stack_node *stack)
{
    int i;
    int median;

    if (!stack)
        return ;
    i = 0;
    median = (stack_lenght(stack)) / 2;
    while (stack)
    {
        stack->index[1] = i;
        if (i < median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}
static t_stack_node    *get_target_node_a(int nbr, t_stack_node *a)
{
    t_stack_node *stack;
    t_stack_node *target_node;
    long closest_bigger;

    closest_bigger = LONG_MAX;
    stack = a;
    while (stack)
    {
        if (stack->nbr > nbr && stack->nbr < closest_bigger)
        {
            closest_bigger = stack->nbr;
            target_node = stack;
        }
        stack = stack->next;
    }
    if (closest_bigger == LONG_MAX)
            target_node = find_min(a);
    return target_node;
}

static int    get_push_cost(t_stack_node *a, t_stack_node *b, t_stack_node *node)
{
    int index_a;
    int index_b;
    int len;

    len = stack_lenght(a);
    if (node->above_median)
        index_a = node->index[1];
    else
        index_a = len - node->index[1];
    len = stack_lenght(b);
    if (node->target_node->above_median)
        index_b = node->target_node->index[1];
    else
        index_b = len - node->target_node->index[1];
    return (index_a + index_b);
}

void    set_cheapest(t_stack_node *stack)
{   
    long    cheapest_push_cost;
    t_stack_node *cheapest_push_node;

    if(!stack)
        return ;
    cheapest_push_cost = LONG_MAX;
    while (stack)
    {
        if (stack->push_cost < cheapest_push_cost)
        {
            cheapest_push_cost = stack->push_cost;
            cheapest_push_node = stack;
        }
        stack = stack->next;
    }
    cheapest_push_node->cheapest = true;
}
void init_a(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *node = a;
    refresh_index(a);
    refresh_index(b);
    while (node)
    {
        node->target_node = get_target_node_a(node->nbr, b);
        node->push_cost = get_push_cost(a, b, node);
        node = node->next;
    }
    set_cheapest(a);
}