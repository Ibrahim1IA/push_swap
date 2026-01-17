/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:40:35 by iissoufo          #+#    #+#             */
/*   Updated: 2025/10/21 00:18:08 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_all(char **arr, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	count_str(char const *s, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_extract_word(char const *s, int len)
{
	char	*word;
	int		j;

	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

static int	fill_array(char const *s, char c, char **ret, int k)
{
	int	i;
	int	len;

	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		if (len > 0)
		{
			ret[k] = ft_extract_word(s + i, len);
			if (!ret[k])
			{
				free_all(ret, k);
				return (-1);
			}
			i += len;
			k++;
		}
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		nb_words;

	if (!s)
		return (NULL);
	nb_words = count_str(s, c);
	ret = (char **)malloc(sizeof(char *) * (nb_words + 1));
	if (!ret)
		return (NULL);
	if (fill_array(s, c, ret, 0) == -1)
		return (NULL);
	ret[nb_words] = NULL;
	return (ret);
}
