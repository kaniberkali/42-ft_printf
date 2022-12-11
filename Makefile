NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
SRC = ft_printf.c \
		ft_puts/ft_putnbr.c \
		ft_puts/ft_putstr.c \
		ft_puts/ft_putchar.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
		cc $(FLAG) -c $(SRC)
		ar rcs $(NAME) *.o

clean:
		rm -f *.o

fclean: clean
		rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re