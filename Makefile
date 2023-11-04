# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/04 18:49:12 by mbuchs            #+#    #+#              #
#    Updated: 2023/11/04 18:57:17 by mbuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
COMP = gcc
CFLAGS = -Wall -Werror -Wextra

SRC = srcs/main.c\

INCLUDES = includes/ft_printf.h\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(COMP) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean :
	rm -f $(OBJBONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all fclean clean re bonus so