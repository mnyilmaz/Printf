NAME: libftprintf.a

SRC: ft_printf.c ft_printf_utils.c

OBJ: ${SRC:s.c=.o}

CFLAGS = -Wall -Wextra -Werror
CC = GCC

$(NAME): $(OBJ)
  		ar rc $(NAME) $(OBJ)
		
clean:
		rm -f $(OBJ) 

fclean: clean
		rm -f $(NAME)

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
