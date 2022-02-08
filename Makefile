# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/02/08 09:22:04 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS_PATH = srcs/
SRCS = $(SRCS_PATH)ft_printf.c $(SRCS_PATH)disp_table.c $(SRCS_PATH)int_print.c \
	$(SRCS_PATH)char_print.c $(SRCS_PATH)str_print.c $(SRCS_PATH)uint_print.c
O_FILES = ft_printf.o disp_table.o int_print.o \
	char_print.o str_print.o uint_print.o
FLAGS = -Wall -Werror -Wextra
LIBFT = libft

all: $(NAME)

$(NAME):
	@echo "Compiling(libft)..."
	@make -C libft
	@echo "Compiling(libftprintf)..."
	@gcc $(FLAGS) -c $(SRCS)
# $(LIBFT)
	@ar rc $(NAME) $(O_FILES)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"
#after this line is just for testing, erase later
	@gcc main.c libftprintf.a libft/libft.a -g
	@echo "Compiling main.c..."
	@echo '\n'a.out ready to \(run\)fire!

clean:
	@echo "Cleaning object files..."
	@rm -f $(O_FILES)
	@make -C libft clean

fclean: clean
	@echo "Cleaning binary..."
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
