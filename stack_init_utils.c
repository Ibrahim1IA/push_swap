
#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	while (src[i] && i < size -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy((str + s1_len), s2, s2_len + 1);
	return (str);
}

char	**merge_args(char **av)
{
	char    *combined;
	char    *tmp;
	char    **res;
	int     i;

	if (!av || !av[0])
	{
		res = malloc(sizeof(char *) * 1);
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	combined = ft_strdup(av[0]);
	i = 1;
	while (av[i])
	{
		tmp = ft_strjoin(combined, " ");
		free(combined);
		combined = ft_strjoin(tmp, av[i++]);
		free(tmp);
	}
	res = ft_split(combined, ' ');
	free(combined);
	return (res);
}
