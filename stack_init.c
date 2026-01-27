/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 22:43:58 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/21 17:59:24 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

static void	append_node(t_stack_node **s, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!s)
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

static long	ft_atol(const char *nptr)
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
	return (nbr * s);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

static int	check_arg(char *arg)
{
	char **parts;
	int j;

	parts = ft_split(arg, ' ');
	if (!parts)
		return (1);
	if (!parts[0])
	{
		free(parts);
		return (1);
	}
	j = 0;
	while (parts[j])
	{
		if (error_syntax(parts[j]))
		{
			while (parts[j])
				free(parts[j++]);
			free(parts);
			return (1);
		}
		free(parts[j++]);
	}
	free(parts);
	return (0);
}

int	verify_args(int ac, char **av)
{
	int i;

	if (ac <= 1)
		return (0);
	i = 1;
	while (av[i])
		if (check_arg(av[i++]))
			return (1);
	return (0);
}

void	merge_and_init(t_stack_node **a, char **av)
{
	char **merged;
	int i;

	merged = merge_args(av);
	if (!merged || !merged[0])
		free_errors(a);
	init_stack_a(a, merged);
	i = 0;
	while (merged && merged[i])
		free(merged[i++]);
	free(merged);
}

void	init_stack_a(t_stack_node **a, char **av)
{
	if (!av || !av[0])
		free_errors(a);
	long			nbr;
	int				i;

	i = 0;
	while (av[i])
	{
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			free_errors(a);
		if (error_duplicate(*a, (int)nbr))
			free_errors(a);
		append_node(a, (int)nbr);
		i++;
	}
	init_sort_index(*a);
}
