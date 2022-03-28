/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/28 12:42:12 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> 						// remove before eval

# define SPECIF "cspdiouxXf*b%"
# define FLAGS "+-#0 "
# define LENGTH "hhllL"
# define ON 1
# define OFF 0
# define NUM_CHECK_DISP sizeof(check_disp_tbl) / sizeof(check_disp_tbl[0])

typedef struct s_var
{
	va_list				ap;
	const char			*fmt;
	int					space_count;
	ssize_t				char_count;
	size_t				astx_ret;
	size_t				len_va_arg;
	int					plus_flag;
	int					minus_flag;
	size_t				width;
	size_t				precision;
	long long			va_ret;
	unsigned long long	va_u_ret;
	int					unnessesary;
	int					hash_flag;
	size_t				zero;
	size_t				zero_count;
	int					zero_flag;
	char				*hold_str;
	int					le_f;
	int					prec_noll;
	int					for_plus;
	int					precision_flag;
	int					char_width;
	int					uint_check;
	int					sign;
	//size_t				float_prec;
}						t_var;

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
void	float_print(t_var *st);
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
void	exec_flag_proc(t_var *st);
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
void	check_signed_length(t_var *st);
void	check_unsigned_length(t_var *st);
void	check_hex_length(t_var *st);
void	check_oct_length(t_var *st);

/*
** Other functions
*/

int		ft_printf(const char *fmt, ...);				//*restrict?
void	parser_loop(t_var *st);
void	check_parser(t_var *st);
void	pf_itoa_base(unsigned long long  nbr, unsigned int base, t_var *st);
void	pf_putint(t_var *st);
size_t	get_it(t_var *st);
void	exec_flags_and_length(t_var *st);
char	*conv_to_str(long long nbr, t_var *st);
char	*uint_str(unsigned long long nbr, t_var *st);
void	initialize_st(const char *format, t_var *st, int flag);
void	pf_print_hex_hash(t_var *st);
void	pf_write_o(t_var *st);
void	pf_write(t_var *st);
void	conv_float_str(long double nbr, t_var *st);

static const t_fptr_print_op print_disp_tbl[14] = {
	char_print,
	str_print,
	address_print,
	int_print,
	int_print,
	oct_print,
	uint_print,
	hex_print,
	hex_print,
	float_print,
	asterix_print,
	binary_print,
	exec_flag_proc,
	null_print,
};

static const t_fptr_flag_op flag_disp_tbl[6] = {
	flag_plus,
	flag_minus,
	hash_flag,
	get_flag_zero,
	get_flag_space,
	null_flag,
};

static const t_fptr_check_op check_disp_tbl[6] = {
	check_width,
	check_precision,
	check_signed_length,
	check_unsigned_length,
	check_hex_length,
	check_oct_length,
};

#endif