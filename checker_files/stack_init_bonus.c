/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 04:43:30 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 04:43:30 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	free_errors(t_stack_node **a, char **args)
{
	free_stack(a);
	free_split_args(args);
	return (0);
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
	long long	nbr;
	int			i;
	int			s;

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

int	init_stack_a(t_stack_node **a, char **av)
{
	long	nbr;
	int		i;

	i = 0;
	while (av[i])
	{
		if (error_syntax(av[i]))
			return (free_errors(a, av));
		nbr = ft_atol(av[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			return (free_errors(a, av));
		if (error_duplicate(*a, (int)nbr))
			return (free_errors(a, av));
		append_node(a, (int)nbr);
		i++;
	}
	return (1);
}
