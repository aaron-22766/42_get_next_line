# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:21:51 by arabenst          #+#    #+#              #
#    Updated: 2022/11/10 15:15:25 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=10

RM		=	rm
RMFLAGS	=	-f

DEPS	=	get_next_line.h
SRC		=	test_main.c \
			get_next_line.c \
			get_next_line_utils.c 
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJ)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re