/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:45:50 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 02:43:29 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	free_split_args(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	parste_and_init(char *str, t_stack_node **a)
{
	char	**args;

	args = ft_split(str, ' ');
	if (!init_stack_a(a, args))
		return (0);
	free_split_args(args);
	return (1);
}
