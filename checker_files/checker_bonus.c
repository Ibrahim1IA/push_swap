/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 21:50:19 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 04:41:47 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_checker(t_checker *commands)
{
	t_checker	*temp;

	while (commands)
	{
		temp = commands;
		commands = commands->next;
		free(temp->command);
		free(temp);
	}
}

static void	free_all_stack(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
}

static void	free_errors_args(char **str)
{
	if (str)
		free(*str);
	write(2, "Error\n", 6);
	exit(1);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	t_checker		*commands;
	char			*args;

	a = NULL;
	b = NULL;
	commands = NULL;
	args = NULL;
	if (ac == 1)
		return (0);
	if (verify_args(&args, av + 1))
		free_errors_args(&args);
	if (!parste_and_init(args, &a))
		free_errors_args(&args);
	free(args);
	save_command(&commands);
	performe_sorting(&a, &b, commands);
	if (stack_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all_stack(&a, &b);
	free_checker(commands);
	return (0);
}
