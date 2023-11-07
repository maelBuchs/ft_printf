NAME	 =	libftprintf.a
COMP	 =	gcc
CFLAGS	 =	-Wall -Werror -Wextra -g
HEAD	=	includes
libft	=	libft/
SRC		=	srcs/ft_printf.c\
			srcs/ft_printf_2.c\
			srcs/ft_printf_3.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) -fPIC $(CFLAGS) -o $@ -c $< -I $(HEAD)

$(NAME) : $(OBJ)
	@make --no-print-directory -C $(libft)
	@mkdir -p temp_libft_objs
	@cd temp_libft_objs && ar -x ../libft/libft.a
	@ar -rcs $(NAME) $(OBJ) temp_libft_objs/*.o
	@rm -rf temp_libft_objs
	

clean :
	@make clean --no-print-directory -C $(libft)
	@rm -f $(OBJ)


fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) libft.a

re : fclean all

.PHONY: all fclean clean re