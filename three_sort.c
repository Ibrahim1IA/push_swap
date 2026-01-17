/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 00:24:18 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/15 01:19:29 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_stack_node **a)
{
    t_stack_node    *biggest_node;

    biggest_node = find_max(*a);
    if (biggest_node == *a)
        ra(a, false);
    else if (biggest_node == (*a)->next)
        rra(a, false);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a, false);
}
