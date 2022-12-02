NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = $(shell find .  -name "*.c")
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
		gcc $(FLAG) -c $(SRC)
		ar rc $(NAME) *.o

clean:
		/bin/rm -f *.o

fclean: clean
		/bin/rm -f $(NAME)

re: 	fclean all

.PHONY: all bonus clean fclean re