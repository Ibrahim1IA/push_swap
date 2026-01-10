#include "push_swap.h"
#include <stdio.h>

void aff(t_stack_node *a, t_stack_node *b)
{
    printf("-------------- Stack A --------------\n");
    while (a)
    {
        printf("\t \t%d\n", a->nbr);
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
    aff(a, b);
    pa(&a, &b);
    aff(a, b);
    pa(&a, &b);
    aff(a, b);
    ra(&a);
    aff(a, b);
    sa(&a);
    aff(a, b);
    rr(&a, &b);
    aff(a, b);
    pa(&a, &b);
    aff(a, b);
    rrr(&a, &b);
    aff(a, b);
    pb(&a, &b);
    aff(a, b);
    sb(&b);
    rb(b);
    aff(a, b);

}