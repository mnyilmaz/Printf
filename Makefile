NAME		= libftprintf.a

SRCS		= ft_printf.c ft_printf_utils.c

OBJS		= ${SRCS:.c=.o}

CFLAGS 		= -Wall -Wextra -Werror
CC 		= @gcc

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar rc $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS) 

fclean: 	clean
			@rm -f $(NAME)

re:		fclean all

com:		re
			@$(CC) $(CFLAGS) $(SRCS) -o main.exe
			@echo "Compiled"
			@./main.exe

.PHONY:		all clean fclean re com
