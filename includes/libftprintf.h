/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/16 13:55:44 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // remove before eval

# define SPECIF "dicsuoxXp*"
# define FLAGS "+-% "
# define ON 1
# define OFF 0

//- %[flags][width][.precision][length]specifier

//# define NUM_DISP sizeof(print_disp_tbl) / sizeof(print_disp_tbl[0]);

/* typedef enum e_flags
{
	PLUS = 1,
	MINUS = 2,
	ERROR = 0
}	t_enum_flags; */

typedef struct s_var
{
	va_list		ap;
	const char		*ptr;
	int			space_count;
	int			char_count;
	int			astx_ret;
	int			len_va_arg;
	//char 		strlen_va_arg;
	int			plus_flag;
	int			minus_flag;
/* 	t_enum_flags	enum_flags[2]; */
	int			width;
	int			width_flag;
	int			precision;
	int			precision_flag;
	int			int_ret;
	int			unnessesary;
}				t_var;

typedef void	(*t_fptr_print_op)(t_var *st);
typedef void	(*t_fptr_flag_op)(t_var *st);

/*
** Functions for print dispatch table
*/

void	int_print(t_var *st);
void	char_print(t_var *st);
void	str_print(t_var *st);
void	uint_print(t_var *st);
void	oct_print(t_var *st);
void	hex_print(t_var *st);
void	address_print(t_var *st);
void	asterix_print(t_var *st);
void	null_print(t_var *st);

//int	binary_print(t_var *st);

/*
** Functions for flags dispatch table
*/

void	flag_plus(t_var *st);
void	flag_minus(t_var *st);
void	procentage_print(t_var *st);
void	get_flag_space(t_var *st);
void	exec_flag_space(t_var *st);
void	null_flag(t_var *st);

/*
** check width and precision functions
*/

void	check_width(t_var *st);
void	exec_width(t_var *st);
void	check_precision(t_var *st);
void	exec_precision(t_var *st);

/*
** Other functions
*/

int		ft_printf(const char *fmt, ...);				//*restrict?
void		parser_loop(t_var *st);
void	check_parser(t_var *st);
char	*pf_itoa_base(long nbr, unsigned int base, const char *ptr);
int		pf_putint(int nbr, t_var *st);

static const t_fptr_print_op print_disp_tbl[11] = {
	int_print,
	int_print,
	char_print,
	str_print,
	uint_print,
	oct_print,
	hex_print,
	hex_print,
	address_print,
	asterix_print,
	null_print,
};

static const t_fptr_flag_op flag_disp_tbl[5] = {
	flag_plus,
	flag_minus,
	procentage_print,
	get_flag_space,
	null_flag,
};

#endif