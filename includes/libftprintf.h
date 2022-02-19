/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/19 19:12:29 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // remove before eval

# define SPECIF "dicsuoxXp*b"
# define FLAGS "+-% #0"
# define LENGTH "hl"
# define ON 1
# define OFF 0
# define NUM_CHECK_DISP sizeof(check_disp_tbl) / sizeof(check_disp_tbl[0])

//- %[flags][width][.precision][length]specifier


/* typedef enum e_flags
{
	PLUS = 1,
	MINUS = 2,
	PROCENT = 4,
	SPACE = 8,
	HASH = 16,
	ERROR = 0
}	t_enum_flags; */


//print order:
    /*
        width (if flagcombo != dash) 
        PLUS FLAG (plus/minus) / - om negativt
        HASHflag (0/0x/0X)
        0 / precision // 0 flag ignored when precision > 0.
        (precision == absolute number of 0 + digits - HASH_num.
        width (if flagcombo == dash)
        
    */

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
/* 	t_enum_flags	enum_flags[3]; */
	int			width;
//	int			width_flag;
	int			precision;
//	int			precision_flag;
	int			int_ret;
	int			unnessesary;
	int			le_short;
	int			le_unsigned_short;
	int			le_signed_char;
	int			hash_flag;
	int			zero;
	int			zero_count;
	int			zero_flag;
}				t_var;

typedef void	(*t_fptr_print_op)(t_var *st);
typedef void	(*t_fptr_flag_op)(t_var *st);
typedef void	(*t_fptr_check_op)(t_var *st);

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
void	binary_print(t_var *st);
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
void	hash_flag(t_var *st);
void	get_flag_zero(t_var *st);
void	exec_flag_zero(t_var *st);
void	null_flag(t_var *st);

/*
** check width and precision functions
*/

void	check_width(t_var *st);
void	exec_width(t_var *st);
void	check_precision(t_var *st);
void	exec_precision(t_var *st);
void	check_length(t_var *st);

/*
** Other functions
*/

int		ft_printf(const char *fmt, ...);				//*restrict?
void	parser_loop(t_var *st);
void	check_parser(t_var *st);
char	*pf_itoa_base(long nbr, unsigned int base, const char *ptr);
void	pf_putint(int nbr, t_var *st);

static const t_fptr_print_op print_disp_tbl[12] = {
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
	binary_print,
	null_print,
};

static const t_fptr_flag_op flag_disp_tbl[7] = {
	flag_plus,
	flag_minus,
	procentage_print,
	get_flag_space,
	hash_flag,
	get_flag_zero,
	null_flag,
};

static const t_fptr_check_op check_disp_tbl[3] = {
	check_width,
	check_precision,
	check_length,
};

#endif