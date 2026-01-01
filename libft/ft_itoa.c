/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 14:48:09 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/21 00:04:17 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	*create_buffer(int n, int is_negatif, int c)
{
	char	*itoa_buffer;

	itoa_buffer = (char *)malloc((c + 1 + is_negatif) * sizeof(char));
	if (!(itoa_buffer))
		return (NULL);
	itoa_buffer[c + is_negatif] = '\0';
	while (c > 0)
	{
		itoa_buffer[--c + is_negatif] = (n % 10) + '0';
		n /= 10;
	}
	if (is_negatif)
		itoa_buffer[0] = '-';
	return (itoa_buffer);
}

char	*ft_itoa(int n)
{
	char	*itoa_buffer;
	int		is_negatif;
	int		nbr;
	int		c;

	c = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_negatif = n < 0;
	if (is_negatif)
		n = -n;
	nbr = n;
	while (nbr / 10 > 0)
	{
		c++;
		nbr /= 10;
	}
	itoa_buffer = create_buffer(n, is_negatif, c);
	return (itoa_buffer);
}
