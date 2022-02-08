# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/02/08 16:39:40 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra

SRCS_PATH = srcs/

FUNCTIONS =	ft_printf \
 			check_ptr \
			int_print \
			char_print \
			str_print \
			uint_print \
			oct_print \
			hex_print

SOURCE_FILES = $(foreach f, $(FUNCTIONS), $(SRCS_PATH)$(f))

SRCS = $(foreach src, $(SOURCE_FILES), $(addsuffix .c, $(src)))

OBJS = *.o

INC = -Iincludes/ -Ilibft/libft.a

all: $(NAME)

$(NAME):
	@echo "Compiling(libft)..."
	@make -C libft
	@echo "Compiling(libftprintf)..."
	@$(CC) $(FLAGS) -c $(SRCS) $(INC)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"
#after this line is just for testing, erase later	
	@gcc main.c libftprintf.a libft/libft.a -g
	@echo "Compiling main.c..."
	@echo '\n'a.out ready to \(run\)fire!

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C libft clean

fclean: clean
	@echo "Cleaning binary..."
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
