# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 18:02:17 by jjolivot          #+#    #+#              #
#    Updated: 2018/09/11 23:14:01 by jjolivot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

LIB = includes/libft/libft.a

SRC = src/main.c src/parsing/ft_parsing.c src/parsing/ft_pars_error.c \
	  src/ls.c src/parsing/ft_file_dir.c src/ft_sort.c src/inforecup/ft_info.c\
	  src/display/ft_display.c src/inforecup/ft_free.c

INC = includes/ls.h

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C includes/libft re
	$(CC) $(CFLAGS) $(LIB) $(SRC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)
re: fclean all
