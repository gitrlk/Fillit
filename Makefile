# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfabre <rfabre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 00:39:27 by rfabre            #+#    #+#              #
#    Updated: 2017/01/25 21:21:06 by jecarol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS += -Wall -Wextra -Werror

SRC = srcs/main.c \
	  srcs/solve.c\
	  srcs/read_input.c\
	  srcs/error.c\
	  srcs/get_coord.c\
	  srcs/parsencheck.c\

LIB =  ./libft/libft.a

CC = cc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -g  $(OBJ) $(LIB) -o $(NAME)

clean:
		/bin/rm -f $(OBJ)

fclean: clean
		/bin/rm -f $(NAME)

re: fclean all

