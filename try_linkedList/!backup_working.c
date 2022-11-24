/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:17:44 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/04 12:40:07 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void			*buf;
	ssize_t			i;
	static ssize_t	bytes_read;
	static t_list	*cache;
	char			*new;
	int				full_line;
	char			*str;
	char			*temp;
	int				s;
	int				j;

	if (fd < 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (NULL);
	full_line = 0;
	while (full_line == 0)
	{
		temp = malloc(BUFFER_SIZE);
		if (!temp)
			return (NULL);
		if (cache)
		{
			temp = (char *)cache->content;
			j = 0;
			while (temp[j] && j < BUFFER_SIZE)
			{
				if (temp[j] == '\n')
				{
					full_line = 1;
					break ;
				}
				j++;
			}
		}
		if (full_line == 0)
		{
			bytes_read = read(fd, buf, BUFFER_SIZE);
			if (bytes_read < 0)
				return (NULL);
			new = malloc(BUFFER_SIZE + 1);
			if (!new)
				return (NULL);
			i = 0;
			while (i < bytes_read)
			{
				new[i] = *(char *)(buf + i);
				if (new[i] == '\n')
					full_line = 1;
				i++;
			}
			new[i] = '\0';
			if (!bytes_read)
			{
				if (!cache)
					return (NULL);
				full_line = 1;
			}
			else
				ft_lstadd_back(&cache, ft_lstnew(new));
		}
		if (full_line == 1)
		{
			if (!(cache->content))
				return (NULL);
			str = malloc(ft_lstsize(cache) * BUFFER_SIZE + 1);
			if (!str)
				return (NULL);
			s = 0;
			while (cache)
			{
				i = 0;
				temp = (char *)cache->content;
				free(cache);
				while (i < BUFFER_SIZE && temp[i] != '\n' && temp[i])
					str[s++] = temp[i++];
				cache = cache->next;
			}
			if (bytes_read)
				str[s] = '\n';
			str[s + 1] = '\0';
			s = 0;
			i++;
			while (i < BUFFER_SIZE && temp[i])
				temp[s++] = temp[i++];
			temp[s] = '\0';
			if (bytes_read)
				cache = ft_lstnew(temp);
			return (str);
		}
	}
	return (NULL);
}
//norminette
//free temp