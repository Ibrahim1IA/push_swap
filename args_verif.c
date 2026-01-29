/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_verif.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 04:44:16 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/29 04:44:17 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_arg(char *arg)
{
	char	**parts;
	int		j;

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

static void	copy_args(char **args, char **av, size_t total_len)
{
	size_t	pos;
	size_t	i;
	size_t	j;

	*args = (char *)malloc(sizeof(char) * total_len);
	if (!*args)
		return ;
	pos = 0;
	i = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
			(*args)[pos++] = av[i][j++];
		(*args)[pos++] = ' ';
		i++;
	}
	(*args)[pos - 1] = '\0';
}

int	verify_args(char **args, char **av)
{
	int		i;
	size_t	total_len;

	i = 0;
	total_len = 0;
	while (av[i])
	{
		if (check_arg(av[i]))
			return (1);
		total_len += ft_strlen(av[i]) + 1;
		i++;
	}
	copy_args(args, av, total_len);
	return (0);
}
