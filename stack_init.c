/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:43:58 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/02 00:19:57 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void append_node(t_stack_node **s, int n)
{
    t_stack_node    *node;
    t_stack_node    *last_node;

    if(!s)
        return ;
    node = malloc(sizeof(t_stack_node));
    if (!node)
        return ;
    node->next = NULL;
    node->nbr = n;
    if (!*s)
    {
        *s = node;
        node->prev = NULL;
    }
    else
    {
        last_node = find_last(*s);
        last_node->next = node;
        node->prev = last_node;
    }
}
void    init_stack_a(t_stack_node **a, char **av)
{
    int nbr;
    int i;

    i = 0;
    while (av[i])
    {
        if (syntax_error(a))
        free_errors(a);
        nbr = ft_atol(av[i]);
        if (nbr > INT_MAX || nbr <INT_MIN)
            free_errors(a);
        if (duplicate_error(a))
            free_errors(a);
        append_node(a, (int)nbr);
        i++;  
    }
}