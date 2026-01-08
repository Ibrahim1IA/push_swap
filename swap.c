/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:12:50 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/08 18:40:15 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack_node **stack)
{
    t_stack_node *tmp;

    if (!*stack || !(*stack)->next)
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    if ((*stack)->next != NULL)
        (*stack)->next->prev = tmp;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->prev = NULL;
    (*stack)->next = tmp;
}
void sa(t_stack_node **a)
{
    swap(a);
}

void sb(t_stack_node **b)
{
    swap(b);
}

void ss(t_stack_node **a, t_stack_node **b)
{
    swap(a);
    swap(b);
}
