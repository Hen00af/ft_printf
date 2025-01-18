# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shattori <shattori@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 19:01:09 by shattori          #+#    #+#              #
#    Updated: 2025/01/18 16:06:10 by shattori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
NAME = libftprintf.a

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
TEST_DIR =  ~/submit/common_core/42common_core_testcode
TEST_DEST_DIR = ./

SRCS = ft_confirm_write.c ft_printf.c ft_put_hexadecimal.c ft_put_unsigned.c ft_putchar_fd.c ft_putnbr_fd.c ft_putptr.c ft_putstr_fd.c ft_strlen.c
SRCS := $(addprefix $(SRC_DIR)/,$(SRCS))
OBJS = ft_confirm_write.o ft_printf.o ft_put_hexadecimal.o ft_put_unsigned.o ft_putchar_fd.o ft_putnbr_fd.o ft_putptr.o ft_putstr_fd.o ft_strlen.o
OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))

TEST = ft_printf_test.c
TEST := $(addprefix $(TEST_DIR)/,$(TEST))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: 
	cp -r $(TEST) $(TEST_DEST_DIR)

.PHONY: all clean fclean re
