NAME := so_long

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := game_logic/*.c
GETNEXTLINE := gnl/*.c
PRINTF := ft_printf/*.c
LIBRARY := -Lminilibx -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx/

all:
	make -C $(MINILIBX)
	@$(CC) $(CFLAGS) $(SOURCE) $(GETNEXTLINE) $(PRINTF) $(LIBRARY) -o $(NAME)

clean:
	make clean -C $(MINILIBX)
fclean: clean	
	rm -rf $(NAME)

re: fclean all