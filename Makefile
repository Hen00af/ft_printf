CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a
SRCS = ft_printf.c ft_decimal_to_hexadecimal.c ft_put_unsigned.c ft_putchar_fd.c ft_putnbr_fd.c ft_putptr.c ft_putstr_fd.c ft_strlen.c
OBJS = ft_printf.o ft_decimal_to_hexadecimal.o ft_put_unsigned.o ft_putchar_fd.o ft_putnbr_fd.o ft_putptr.o ft_putstr_fd.o ft_strlen.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

