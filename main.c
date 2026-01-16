#include "push_swap.h"
#include <stdio.h>

void aff(t_stack_node *a, t_stack_node *b)
{
    printf("-------------- Stack A --------------\n");
    while (a)
    {
        printf("\t Index : %d\tNbr :%d\t push price : %d \t target node : %d\t is cheapest : %d\t above median : %d\n", a->index, a->nbr, a->push_cost, a->target_node->nbr, a->cheapest, a->above_median);
        a = a->next;
    }
    printf("-------------- Stack B --------------\n");
    while (b)
    {
        printf("\t%d\n", b->nbr);
        b = b->next;
    }
}
int main(int ac, char **av)
{
    (void)ac;
    t_stack_node *a= NULL;
    t_stack_node *b = NULL;
    init_stack_a(&a, av +1);
    pb(&a, &b, true);
    pb(&a, &b, true);
    pb(&a, &b, true);
    pb(&a, &b, true);
    init_a(a, b);
    aff(a, b);
//gcc -Wall -Wextra -Werror stack_init.c stack_utils.c push.c swap.c reverse_rotatate.c rotate.c main.c init_a.c
//./a.out 42 2 58 41 38 96 4 523 10 18 98 64 33 73
}