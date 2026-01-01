/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:24:09 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/01 22:29:40 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack_node    *a;
    t_stack_node    *b;
    char            *args;

    a = NULL;
    b = NULL;
    if (ac == 1 || (ac ==2 && !av[1][0]))
        return (1);
    else if (ac == 2)
        args = ft_split(av, ' ');
    init_stack_a(&a, av + 1);
    if (!stack_sorted(a))
    {
        if (stack_lenght(a)== 2)
            sa(&a, false);
        else if (stack_lenght(a) == 3)
            sort_three(&a);
        else
            sort_stack(&a, &b);
    }
    free_stack(&a);
    return (0);
}