/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:09:59 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/14 11:10:01 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str_d;

	i = 0;
	str = (char *)src;
	str_d = (char *)dest;
	if (src == dest)
		return ((void *)src);
	while (i < n)
	{
		str_d[i] = str[i];
		i++;
	}
	return (str_d);
}
