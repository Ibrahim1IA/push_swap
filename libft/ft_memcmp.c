/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:20:34 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/15 13:20:35 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*temp1;
	const unsigned char	*temp2;
	size_t				i;

	i = 0;
	if (n == 0)
		return (0);
	temp1 = (const unsigned char *)s1;
	temp2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (temp1[i] != temp2[i])
			return ((int)(temp1[i] - temp2[i]));
		i++;
	}
	return (0);
}
