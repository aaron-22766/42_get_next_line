/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:16:32 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/12 11:30:38 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_to_cache(int fd, char *cache)
{
	char		*buf;
	ssize_t		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (!ft_strrchr(cache, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		cache = ft_strjoin(cache, buf);
	}
	free(buf);
	return (cache);
}

char	*ft_make_line(char *cache)
{
	int		i;
	char	*new;

	if (!cache[0])
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
		i++;
	new = malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (cache[i] && cache[i] != '\n')
	{
		new[i] = cache[i];
		i++;
	}
	if (cache[i] == '\n')
	{
		new[i] = cache[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_save_rest(char *cache)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	if (!cache)
		return (NULL);
	while (cache[i] && cache[i - 1] != '\n')
		i++;
	if (!cache[i])
	{
		free(cache);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(cache + i) + 1));
	if (!rest)
		return (NULL);
	j = 0;
	while (cache[i])
		rest[j++] = cache[i++];
	rest[j] = '\0';
	free(cache);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cache = ft_read_to_cache(fd, cache);
	if (!cache)
		return (NULL);
	line = ft_make_line(cache);
	cache = ft_save_rest(cache);
	return (line);
}
