NAME	 =	libftprintf.a
COMP	 =	clang
CFLAGS	 =	-Wall -Werror -Wextra
HEAD	=	includes/ft_printf.h
libft	=	libft/
SRC		=	main.c\
			srcs/ft_printf.c

OBJ = $(SRC:.c=.o)

all : $(NAME)
t : test

%.o : %.c
	@$(COMP) $(CFLAGS) -o $@ -c $< -I $(HEAD)

$(NAME) : $(OBJ)
	@make --no-print-directory -C $(libft)
	@cp libft/libft.a libft.a
	@ar -rcs $(NAME) $(OBJ) libft.a


test : $(OBJ)
	@make --no-print-directory -C $(libft)
	@cp libft/libft.a libft.a
	gcc -g $(CFLAGS) -o ft_printf $(OBJ) libft.a

clean :
	@make clean --no-print-directory -C $(libft)
	@rm -f $(OBJ)



fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) libft.a


re : fclean all

.PHONY: all fclean clean re