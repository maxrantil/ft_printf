# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/05/04 13:27:59 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
FLAGS	=	-Wall -Werror -Wextra -O3
LIBFT	=	libft
LIBS	=	libft.a

SRCS 	=	srcs/ft_printf.c \
			srcs/print_int_address.c \
			srcs/print_c_str.c \
			srcs/print_uint_binary.c \
			srcs/print_null_float_oct.c \
			srcs/print_hex_astrix_procent.c \
			srcs/float_work.c \
			srcs/flags_plus_minus_hash_null.c \
			srcs/flags_proc_zero_space.c \
			srcs/width_and_precision.c \
			srcs/tools_write_flags.c \
			srcs/tools_itoa_b_getit_nullprint.c \
			srcs/colors.c
		
OBJS	=	ft_printf.o \
			print_int_address.o \
			print_c_str.o \
			print_uint_binary.o \
			print_null_float_oct.o \
			print_hex_astrix_procent.o \
			float_work.o \
			flags_plus_minus_hash_null.o \
			flags_proc_zero_space.o \
			width_and_precision.o \
			tools_write_flags.o \
			tools_itoa_b_getit_nullprint.o \
			colors.o

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling(libft)..."
	@make -C $(LIBFT)
	@echo "libft done."
	@cp $(LIBFT)/$(LIBS) ./$@
	@echo "Compiling(libftprintf)..."
	@gcc $(FLAGS) -c $(SRCS)
	@ar rc $(NAME) $(OBJS)
	@echo "$@ created"
	@ranlib $@
	@echo "$@ indexed"

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
