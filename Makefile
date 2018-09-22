# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/04 18:02:17 by jjolivot          #+#    #+#              #
#    Updated: 2018/09/22 18:53:27 by jjolivot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

LIB = includes/libft/libft.a

SRC = srcs/main.c srcs/parsing/ft_parsing.c srcs/parsing/ft_pars_error.c \
	  srcs/ls.c srcs/parsing/ft_file_dir.c srcs/ft_sort_arg.c \
	  srcs/inforecup/ft_info.c srcs/ft_sort_file2.c\
	  srcs/display/ft_display.c srcs/inforecup/ft_free.c srcs/ft_sort_file.c\
	  srcs/parsing/ft_pars_error2.c srcs/display/ft_misc.c

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
