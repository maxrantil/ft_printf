# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/02/01 18:33:02 by mrantil          ###   ########.fr        #
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
#after this line is just for testing, erase later	
	@gcc main.c libftprintf.a libft/libft.a -g
	@echo "Compiling main.c..."
	@echo '\n'a.out ready to fire!

clean:
	@echo "Cleaning object files..."
	@make -C libft clean

fclean: clean
	@echo "Cleaning binary..."
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
