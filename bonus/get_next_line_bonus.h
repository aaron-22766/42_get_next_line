/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 08:14:09 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/14 13:12:11 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

typedef struct s_chain
{
	int				fd;
	char			*str;
	struct s_chain	*next;
}					t_chain;

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
void	ft_strjoin(char **s1, char *s2);
t_chain	*ft_get_from_fd(int fd, t_chain **head);

#endif