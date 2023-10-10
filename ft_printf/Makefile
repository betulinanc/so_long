SRC = 	ft_printf.c \
		printf_utils.c \
		ft_itoa.c \
		printf_utils2.c

OBJS = $(SRC:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a


all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS) 
	
fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette *.[ch]

.PHONY: all clean fclean re norm