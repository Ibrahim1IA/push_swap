/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:31:41 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/19 14:31:43 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	long	div;

	nbr = n;
	div = 1;
	if (fd < 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	while (nbr / div > 9)
		div *= 10;
	while (div > 0)
	{
		ft_putchar_fd(((nbr / div) + 48), fd);
		nbr %= div;
		div /= 10;
	}
}
