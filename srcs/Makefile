SRC			= ft_putstr_fd.c ft_split.c ft_strchr.c ft_strjoin.c ft_substr.c ft_putchar_fd.c ft_calloc.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_striteri.c ft_replace.c
OBJS		= ${SRC:.c=.o}
HEAD		= lib.h
NAME		= lib.a
GCC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

%.o: %.c
			${GCC} ${CFLAGS} -c -I ${HEAD} $< -o $@

${NAME}:	${OBJS}
			ar -rcs $(NAME) $^

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
