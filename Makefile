
SRC = pipex.c pipex_utiles.c pipex_utiles_2.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIBFT = srcs/lib.a
GFLAGS = -Wall -Wextra -Werror
NAME = pipex

all: $(NAME)

$(NAME): $(SRC)
	cd srcs && make && cd ..
	$(CC) $(GFLAGS) $(SRC) $(LIBFT) -o $(NAME) -fsanitize=address

clean :
	cd srcs && make clean && cd ..

fclean : clean
	cd srcs && make fclean && cd ..
	rm -rf $(NAME)

bonus :
	cd srcs && make && cd ..
	$(CC) $(GFLAGS) $(SRC) $(LIBFT) -o $(NAME) -fsanitize=address

re : fclean all

.PHONY: all clean fclean re