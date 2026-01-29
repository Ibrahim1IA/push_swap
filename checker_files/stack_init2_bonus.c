/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:45:50 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 00:39:50 by iissoufo         ###   ########.fr       */
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

void	parste_and_init(char *str, t_stack_node **a)
{
	char	**args;

	args = ft_split(str, ' ');
	free(str);
	init_stack_a(a, args);
	free_split_args(args);
}
