/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:50:19 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/23 11:21:32 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	if (ft_strcmp(command, "sa") == 0)
		sa(a, 1);
	else if (ft_strcmp(command, "sb") == 0)
		sb(b, 1);
	else if (ft_strcmp(command, "ss") == 0)
		ss(a, b, 1);
	else if (ft_strcmp(command, "pa") == 0)
		pa(a, b, 1);
	else if (ft_strcmp(command, "pb") == 0)
		pb(a, b, 1);
	else if (ft_strcmp(command, "ra") == 0)
		ra(a, 1);
	else if (ft_strcmp(command, "rb") == 0)
		rb(b, 1);
	else if (ft_strcmp(command, "rr") == 0)
		rr(a, b, 1);
	else if (ft_strcmp(command, "rra") == 0)
		rra(a, 1);
	else if (ft_strcmp(command, "rrb") == 0)
		rrb(b, 1);
	else if (ft_strcmp(command, "rrr") == 0)
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}

static void	performe_sorting(t_stack_node **a, t_stack_node **b)
{
	char	*command;
	int		len;

	while (1)
	{
		command = get_next_line(0);
		if (!command)
			break ;
		len = ft_strlen(command);
		if (len > 0 && command[len - 1] == '\n')
			command[len - 1] = '\0';
		if (!execute_command(command, a, b))
		{
			free(command);
			free_stack(a);
			free_stack(b);
			write(2, "Error\n", 6);
			exit(1);
		}
		free(command);
	}
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (0);
	else if (ac == 2)
		parste_and_init(av[1], &a);
	else
		init_stack_a(&a, av + 1);
	performe_sorting(&a, &b);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
