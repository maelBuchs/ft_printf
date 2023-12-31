# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbuchs <mael@buchs.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 18:11:04 by mbuchs            #+#    #+#              #
#    Updated: 2023/11/05 16:32:47 by mbuchs           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
COMP = gcc
CFLAGS = -Wall -Werror -Wextra

LIB = ft_strlen.c\
	ft_atoi.c\
	ft_strdup.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strncmp.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isprint.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_memset.c\
	ft_strnstr.c\
	ft_memcmp.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memchr.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_lstadd_back_bonus.c\
	ft_lstadd_front_bonus.c\
	ft_lstlast_bonus.c\
	ft_lstnew_bonus.c\
	ft_lstsize_bonus.c\
	ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c\
	ft_lstiter_bonus.c\
	ft_lstmap_bonus.c\

SRC = $(LIB) $(ADDITIONAL)

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

so:
	@$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS)
	@gcc -nostartfiles -shared -o libft.so $(OBJBONUS)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)
	@rm -f libft.so

re : fclean all

.PHONY: all fclean clean re bonus so
