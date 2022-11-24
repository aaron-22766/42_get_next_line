/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   !backup_normtry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:17:44 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/06 15:09:30 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_cache_rest(t_list *cache)
{
	char	*temp;
	int		i;

	temp = malloc(BUFFER_SIZE);
	if (!temp)
		return (-1);
	if (cache)
	{
		temp = (char *)cache->content;
		i = 0;
		while (temp[i] && i < BUFFER_SIZE)
		{
			if (temp[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_read_to_cache(int fd, t_list **cache, ssize_t *bytes_read)
{
	void	*buf;
	char	*new;
	ssize_t	i;
	int		full_line;

	buf = malloc(BUFFER_SIZE);
	if (!buf)
		return (-1);
	*bytes_read = read(fd, buf, BUFFER_SIZE);
	if (*bytes_read < 0)
		return (-1);
	new = malloc(BUFFER_SIZE + 1);
	if (!new)
		return (-1);
	i = 0;
	full_line = 0;
	while (i < *bytes_read)
	{
		new[i] = *(char *)(buf + i);
		if (new[i] == '\n')
			full_line = 1;
		i++;
	}
	new[i] = '\0';
	if (!*bytes_read)
	{
		if (!*cache) //free buf
			return (-1);
		full_line = 1;
	}
	else
		ft_lstadd_back(cache, ft_lstnew(new));
	free(buf);
	return (full_line);
}

char	*ft_make_str(t_list **cache, ssize_t bytes_read)
{
	char	*temp;
	char	*str;
	ssize_t	i;
	int		s;

	if (!(*cache)->content)
		return (NULL);
	str = malloc(ft_lstsize(*cache) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	temp = malloc(BUFFER_SIZE);
	if (!temp)
		return (NULL);
	s = 0;
	while (*cache)
	{
		i = 0;
		temp = (char *)(*cache)->content;
		free((*cache)->content);
		while (i < BUFFER_SIZE && temp[i] != '\n' && temp[i])
			str[s++] = temp[i++];
		*cache = (*cache)->next;
	}
	if (bytes_read)
		str[s] = '\n';
	str[s + 1] = '\0';
	s = 0;
	i++;
	while (i < BUFFER_SIZE && temp[i])
		temp[s++] = temp[i++];
	temp[s] = '\0';
	free(*cache);
	printf("%zi\n", bytes_read);
	if (bytes_read)
		*cache = ft_lstnew(temp);
	printf("%p\n", cache);
	printf("%s\n", (*cache)->content);
	return (str);
}

char	*get_next_line(int fd)
{
	static ssize_t	bytes_read;
	static t_list	*cache;
	int				full_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	full_line = 0;
	printf("%p\n", cache);
	while (full_line == 0)
	{
		full_line = ft_cache_rest(cache);
		if (full_line == 0)
			full_line = ft_read_to_cache(fd, &cache, &bytes_read);
	}
	if (full_line == 1)
		return (ft_make_str(&cache, bytes_read));
	return (NULL);
}
//norminette
//free