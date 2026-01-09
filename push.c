/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 17:41:14 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/09 20:51:24 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *tmp;

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

void pa(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
}

void pb(t_stack_node **a, t_stack_node **b)
{
    push(b, a);
}