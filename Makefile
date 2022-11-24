# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 12:21:51 by arabenst          #+#    #+#              #
#    Updated: 2022/11/14 15:17:24 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	get_next_line

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -D BUFFER_SIZE=10000000

RM		=	rm
RMFLAGS	=	-f

DEPS	=	get_next_line.h
SRC		=	get_next_line.c \
			get_next_line_utils.c \
			test_main.c
OBJ		=	$(SRC:.c=.o)

BDEPS	=	get_next_line_bonus.h
BSRC	=	get_next_line_bonus.c \
			get_next_line_utils_bonus.c \
			test_bonus.c
BOBJ	=	$(BSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJ)

bonus: $(BOBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(BOBJ)
	
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re