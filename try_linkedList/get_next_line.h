/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 12:17:42 by arabenst          #+#    #+#             */
/*   Updated: 2022/11/04 11:06:11 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
char	*get_next_line(int fd);

#endif
