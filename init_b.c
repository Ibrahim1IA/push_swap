

#include "push_swap.h"

static t_stack_node    *get_target_node_b(int nbr, t_stack_node *a)
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

void    init_b(t_stack_node *a, t_stack_node *b)
{
    refresh_index(a);
    refresh_index(b);
    while (b)
    {
        b->target_node = get_target_node_b(b->nbr, a);
        b = b->next;
    }
}