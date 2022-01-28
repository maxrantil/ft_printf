# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/01/28 12:00:00 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c
O_FILES = $(SRCS:.c=.o)
FLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	@echo "Compiling(libft)..."
	@make -C libft
	@echo "Compiling(libftprintf)..."
	@gcc $(FLAGS) -c $(SRCS) -I $(LIBFT)
	@ar rc $(NAME) $(O_FILES)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

clean:
	@echo "Cleaning object files..."
	@make -C libft clean

fclean: clean
	@echo "Cleaning binary..."
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
