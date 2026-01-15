/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 18:43:31 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/15 00:06:00 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack_node **stack)
{
    t_stack_node *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    last = find_last(*stack);
    last->next = *stack;
    (*stack)->prev = last;
    (*stack) = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->next = NULL;
}

void    ra(t_stack_node **a, bool print)
{
    rotate(a);
    if (!print)
        write(1, "ra\n", 3);
}

void    rb(t_stack_node **b, bool print)
{
    rotate(b);
    if (!print)
        write(1, "rb\n", 3);
}

void    rr(t_stack_node **a, t_stack_node **b, bool print)
{
    rotate(a);
    rotate(b);
    if (!print)
        write(1, "rr\n", 3);
}