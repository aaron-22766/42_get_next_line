/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:16:32 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/12 15:25:05 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read_to_cache(int fd, char **cache)
{
	char		*buf;
	ssize_t		bytes_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	bytes_read = 1;
	while (!ft_strrchr(*cache, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			free(*cache);
			*cache = NULL;
			return ;
		}
		buf[bytes_read] = '\0';
		ft_strjoin(cache, buf);
	}
	free(buf);
}

void	ft_make_line(char **cache, char **line)
{
	int		i;

	if (!(*cache) || !(*cache)[0])
		return ;
	i = 0;
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	*line = malloc(sizeof(char) * (i + 2));
	if (!(*line))
		return ;
	i = 0;
	while ((*cache)[i] && (*cache)[i] != '\n')
	{
		(*line)[i] = (*cache)[i];
		i++;
	}
	if ((*cache)[i] == '\n')
	{
		(*line)[i] = (*cache)[i];
		i++;
	}
	(*line)[i] = '\0';
}

void	ft_save_rest(char **cache)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	if (!(*cache))
		return ;
	while ((*cache)[i] && (*cache)[i] != '\n')
		i++;
	if (!(*cache)[i])
	{
		free(*cache);
		*cache = NULL;
		return ;
	}
	i++;
	rest = malloc(sizeof(char) * (ft_strlen(*cache + i) + 1));
	if (!rest)
		return ;
	j = 0;
	while ((*cache)[i])
		rest[j++] = (*cache)[i++];
	rest[j] = '\0';
	free(*cache);
	*cache = rest;
}

char	*get_next_line(int fd)
{
	static char	*cache;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	ft_read_to_cache(fd, &cache);
	ft_make_line(&cache, &line);
	ft_save_rest(&cache);
	return (line);
}
