# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjolivot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 22:25:10 by jjolivot          #+#    #+#              #
#    Updated: 2018/07/28 20:12:37 by jjolivot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_putchar_fd.c ft_putchar.c ft_putstr_fd.c ft_putstr.c \
	ft_strlen.c ft_putendl_fd.c ft_putendl.c ft_memalloc.c ft_strnew.c \
	ft_memdel.c ft_strdel.c ft_strclr.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_isalpha.c \
	ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_itoa.c \
	ft_putnbr.c ft_putnbr_fd.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
	ft_strtrim.c ft_strsplit.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c  \
	ft_wl.c ft_wc.c ft_print_words_tables.c ft_rtn_bigger.c ft_rtn_smaller.c \
	ft_digitnbr.c ft_f_strjoin.c ft_all_free.c ft_tab_size.c \
	get_next_line.c ft_10_to_8.c ft_power.c ft_is_alpha_sort.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRC)
	ar r $(NAME) $(OBJ)
	ranlib $(NAME)
	rm -f $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
