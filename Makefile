BGreen	=	$(shell echo "\033[1;32m")
RESET	=	$(shell echo "\033[0m")
BRed	=	$(shell echo "\033[1;31m")
NAME	 =	libftprintf.a
COMP	 =	gcc
CFLAGS	 =	-Wall -Werror -Wextra
HEAD	=	includes/
libft	=	libft/
SRC		=	main.c\
			srcs/ft_printf.c\
			srcs/print_hexa.c\

#ft_printf2.c\
#ft_printf3.c\

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	@$(COMP) -fPIC $(CFLAGS) -o $@ -c $< -I $(HEAD)

#$(NAME) : $(OBJ)
#	@make --no-print-directory -C $(libft)
#	@ar -rcs $(NAME) $(OBJ) libft/libft.a
#	gcc -g $(CFLAGS) -o ft_printf $(OBJ) libft.a
#	@echo "$(BGreen)Compilation OK$(RESET)"
  

$(NAME) : $(OBJ)
	@make --no-print-directory -C $(libft)
	@mkdir -p temp_libft_objs
	@cd temp_libft_objs && ar -x ../libft/libft.a
	@ar -rcs $(NAME) $(OBJ) temp_libft_objs/*.o
	@rm -rf temp_libft_objs
	@echo "$(BGreen)Compilation OK$(RESET)"
	

clean :
	@make clean --no-print-directory -C $(libft)
	@rm -f $(OBJ)
	@echo "$(BRed)Erase .o files$(RESET)"


fclean : clean
	@make fclean --no-print-directory -C $(libft)
	@rm -f $(NAME) libft.a
	@echo "$(BRed)Erase $(NAME) and libft.a$(RESET)"

test : re
	@gcc -g main.c srcs/ft_printf.c -L./libft -lft -o test && ./test

re : fclean all

.PHONY: all fclean clean re