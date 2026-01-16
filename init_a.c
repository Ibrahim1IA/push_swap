/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 17:54:51 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/16 02:49:11 by iissoufo         ###   ########.fr       */
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
    median = stack_lenght(stack)/2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_median = true;
        else
            stack->above_median = false;
        stack = stack->next;
        i++;
    }
}
t_stack_node    *get_target_node_a(int nbr, t_stack_node *b)
{
    t_stack_node *stack;
    t_stack_node *target_node;
    int closest_smaller;

    closest_smaller = 0;
    stack = b;
    while (stack)
    {
        if (stack->nbr < nbr && stack->nbr > closest_smaller)
        {
            closest_smaller = stack->nbr;
            target_node = stack;
        }
    }
    if (target_node == LONG_MIN)
            target_node = find_max(b);
    return target_node;
}

int    get_push_cost(t_stack_node *a, t_stack_node *b)
{
    int index_a;
    int index_b;
    int len;

    len = stack_lenght(a);
    if (a->above_median)
        index_a = a->index;
    else
        index_a = len - a->index;
    len = stack_lenght(b);
    if (a->target_node->above_median)
        index_b = a->target_node->index;
    else
        index_b = len - a->target_node->index;
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
    refresh_index(a);
    refresh_index(b);
    while (a)
    {
        a->target_node = get_target_node_a(a->nbr, b);
        a->push_cost = get_push_cost(a, a->target_node);
        a = a->next;
    }
    set_cheapest(a);
}