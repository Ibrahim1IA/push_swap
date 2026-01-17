/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:26:24 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/20 23:55:58 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
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
		if (nbr > (LONG_MAX - (nptr[i] - '0')) / 10)
		{
			if (s > 0)
				return (-1);
			else
				return (0);
		}
		nbr = (nbr * 10) + (nptr[i++] - 48);
	}
	return ((int)(nbr * s));
}
