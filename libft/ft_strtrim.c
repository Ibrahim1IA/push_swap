/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:16:18 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/17 12:16:19 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_set(char const *set, char const c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_set(set, s1[end - 1]))
		end--;
	len = end - start + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + start), len);
	return (str);
}
