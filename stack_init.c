/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:43:58 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/15 01:48:04 by iissoufo         ###   ########.fr       */
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

static int	ft_atol(const char *nptr)
{
	long	nbr;
	int		i;
	int		s;

	i = 0;
	s = 1;
	nbr = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			s = -s;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i++] - 48);
	}
	return ((int)(nbr * s));
}
t_stack_node    *get_cheapest(t_stack_node *stack)
{
    if (!stack)
        return (NULL);
    while(stack)
    {
        if (stack->cheapest)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}
/* void    init_stack_a(t_stack_node **a, char **av)
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
} */
void    init_stack_a(t_stack_node **a, char **av)
{
    int nbr;
    int i;

    i = 0;
    while (av[i])
    {
        nbr = ft_atol(av[i]);
        append_node(a, (int)nbr);
        i++;  
    }
}

void    bring_on_top(t_stack_node **stack, t_stack_node *top, bool i)
{
    while (*stack != top)
    {
        if (!i)
        {
            if(top->above_median)
                ra(stack,false);
            else
                rra(stack, false);
        }
        else
        {
            if(top->above_median)
                rb(stack, false);
            else
                rrb(stack, false);
        }
    }
}