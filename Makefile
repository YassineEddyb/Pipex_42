
SRC = pipex.c pipex_utiles.c pipex_utiles_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIBFT = libft/libft.a
GFLAGS = -Wall -Wextra -Werror
NAME = pipex

all: $(NAME)

$(NAME): $(SRC)
	cd libft && make && cd ..
	$(CC) $(SRC) $(LIBFT) -o $(NAME)

clean :
	cd libft && make clean && cd ..

fclean : clean
	cd libft && make fclean && cd ..
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re