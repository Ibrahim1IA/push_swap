/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotatate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:58:26 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/09 20:51:06 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
    t_stack_node    *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return ;
    last = find_last(*stack);
    (*stack)->prev = last;
    last->prev->next = NULL;
    last->next = *stack;
    last->prev = NULL;
    (*stack) = (*stack)->prev;
}

void    rra(t_stack_node **a)
{
    reverse_rotate(a);
}

void    rrb(t_stack_node **b)
{
    reverse_rotate(b);
}

void    rrr(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
}