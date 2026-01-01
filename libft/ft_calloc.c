/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 09:51:44 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/16 09:51:45 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	len;
	void	*mem;

	if (size > 0 && (nmemb > SIZE_MAX / size))
		return (NULL);
	len = size * nmemb;
	mem = malloc(len);
	if (!mem)
		return (NULL);
	ft_bzero(mem, len);
	return (mem);
}
