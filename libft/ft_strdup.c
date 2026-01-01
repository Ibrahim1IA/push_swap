/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:53:05 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/16 11:53:07 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;

	len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, len + 1);
	res[len] = '\0';
	return (res);
}
