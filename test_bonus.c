/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 07:57:36 by nikito            #+#    #+#             */
/*   Updated: 2022/11/14 11:12:06 by arabenst         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd3;
	int		fd4;
	int		fd5;
	char	*line3;
	char	*line4;
	char	*line5;

	fd3 = open("fd3.txt", O_RDONLY);
	fd4 = open("fd4.txt", O_RDONLY);
	fd5 = open("fd5.txt", O_RDONLY);
	while (1)
	{
		line3 = get_next_line(fd3);
		printf("%s", line3);
		line4 = get_next_line(fd4);
		printf("%s", line4);
		line5 = get_next_line(fd5);
		printf("%s", line5);
		if (!line3 && !line4 && !line5)
			break ;
	}
	free(line3);
	free(line4);
	free(line5);
	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}
