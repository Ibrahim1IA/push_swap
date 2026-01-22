
#include "push_swap.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	execute_command(char *command, t_stack_node **a, t_stack_node **b)
{
	if (ft_strcmp(command, "sa\n") == 0)
		sa(a, 1);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b, 1);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(command, "pa\n") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a, 1);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b, 1);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a, 1);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b, 1);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}

static int	performe_sorting(t_stack_node **a, t_stack_node **b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (!execute_command(command, a, b))
		{
			free(command);
			write(2, "Error\n", 6);
			return (0);
		}
		free(command);
		command = get_next_line(0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		parste_and_init(av[1], &a);
	else
		init_stack_a(&a, av + 1);
	if (!performe_sorting(&a, &b))
		return (1);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
