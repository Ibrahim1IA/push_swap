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
        printf("\tIndex : %d\tNbr :%d\tTarget node : %d\n", b->index, b->nbr, b->target_node->nbr);
        b = b->next;
    }
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;

	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int main(int ac, char **av)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;
    int *array;

    if (ac < 2)
        return (0);

    init_stack_a(&a, av + 1);
    array = get_sorted_stack_in_array(a);
    sort_stack(&a, &b, array);
    //aff(a, b);
    free(array);
    free_stack(&a);
    return (0);
}
