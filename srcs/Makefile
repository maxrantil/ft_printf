# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/03/24 19:50:49 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
WFLAGS = -Wall -Werror -Wextra -g -O3
# -Wconversion -O3

IDIR = ../includes
HFILE = -I$(IDIR)

ODIR = obj
LDIR = ../libft

LIBS = libft.a

_DEPS = libftprintf.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

FUNCTIONS = ft_printf \
			print_int \
			print_bi_add_c_str \
			print_uint \
			print_null_float_oct \
			print_hex_astrix \
			float_print \
			flags_plus_minus_hash_null \
			flags_proc_zero_space \
			width_and_precision \
			tools

_OBJ = $(foreach function, $(FUNCTIONS), $(function).o)
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

SRCS = $(foreach function, $(FUNCTIONS), $(function).c)

$(ODIR)/%.o: %.c $(DEPS)
	@$(CC) $(WFLAGS) -c -o $@ $< $(HFILE)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Compiling(libft)..."
	@make -C $(LDIR)
	@echo "libft done."

	@cp $(LDIR)/$(LIBS) $@
	@echo "Compiling(libftprintf)..."
#	@$(CC) $(WFLAGS) -c $(SRCS)
	@ar rc $@ $^
	@echo "$@ created"
	@ranlib $@
	@echo "$@ indexed"
#after this line is just for testing, erase later
	@gcc main.c $@ $(HFILE) -I$(LDIR) -g -O3
	@echo "Compiling main.c..."
	@echo '\n'a.out ready to \(run\)fire!

clean:
	@echo "Cleaning object files..."
	@rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	@echo "/obj clean."
	@make -C $(LDIR) clean
	@echo "libft clean."

fclean: clean
	@echo "Cleaning .a files..."
	@make -C $(LDIR) fclean
	@rm -f $(NAME)
	@echo "libft.a & ibftprintf.a gone."

re: fclean all

.PHONY: all clean fclean re




#	@ar rc $(NAME) $(O_FILES)
#	@echo "$(NAME) created"
#	@ranlib $(NAME)
#	@echo "$(NAME) indexed"
#after this line is just for testing, erase later
#	@gcc main.c libftprintf.a libft/libft.a -g
#	@echo "Compiling main.c..."
#	@echo '\n'a.out ready to \(run\)fire!




