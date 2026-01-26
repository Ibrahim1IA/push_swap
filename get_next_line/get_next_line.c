/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iissoufo <iissoufo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:52:51 by iissoufo          #+#    #+#             */
/*   Updated: 2026/01/23 11:49:59 by iissoufo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if ((const unsigned char)s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		i;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	free(stash);
	return (new_stash);
}

char	*set_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	if (!*stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	return (line);
}

char	*fill_line_buffer(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	int		i;

	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (!ft_strchr(stash, '\n') && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[i] = '\0';
		tmp = stash;
		stash = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stash = fill_line_buffer(fd, stash);
	if (!stash)
		return (NULL);
	line = set_line(stash);
	stash = clean_stash(stash);
	return (line);
}
