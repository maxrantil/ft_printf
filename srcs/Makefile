# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 15:01:43 by mrantil           #+#    #+#              #
#    Updated: 2022/03/02 17:36:07 by mrantil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
WFLAGS = -Wall -Werror -Wextra -g
# -Wconversion -O3

IDIR = ../includes
HFILE = -I$(IDIR)

ODIR = obj
LDIR = ../libft

LIBS = libft.a

_DEPS = libftprintf.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

FUNCTIONS = ft_printf \
			parser_loop \
			int_print \
			char_print \
			str_print \
			uint_print \
			oct_print \
			hex_print \
			address_print \
			float_print \
			asterix_print \
			binary_print \
			null_print \
			flags \
			check_width_and_precision

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
	@gcc main.c $@ $(HFILE) -I$(LDIR) -g
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




