/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:52:07 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // remove before eval

# define SPECIF "dicsuoxXp*"
# define FLAGS "+%"
# define ON 1
# define OFF 0

//- %[flags][width][.precision][length]specifier

//# define NUM_DISP sizeof(print_disp_tbl) / sizeof(print_disp_tbl[0]);

typedef struct s_var
{
	va_list		ap;
	const char		*ptr;
	int			space_count;
	int			char_count;
	int			astx_ret;
	int			len_va_arg;
	//char 		strlen_va_arg;
	int			flag;
	int			width;
}				t_var;

typedef int	(*t_fptr_print_op)(t_var *st);
typedef int	(*t_fptr_flag_op)(t_var *st);

/*
** Functions for print dispatch table
*/

int	ft_printf(const char *fmt, ...);				//*restrict?
int	int_print(t_var *st);
int	char_print(t_var *st);
int	str_print(t_var *st);
int	uint_print(t_var *st);
int	oct_print(t_var *st);
int	hex_print(t_var *st);
int	address_print(t_var *st);
int	asterix_print(t_var *st);

//int	binary_print(t_var *st);

/*
** Functions for flags dispatch table
*/

int	flag_plus(t_var *st);

/*
** check_width
*/

int	check_width(t_var *st);

/*
** Other functions
*/

int		parser_loop(t_var st);
int		check_parser(t_var *st);
char	*pf_itoa_base(long nbr, unsigned int base, const char *ptr);
int		procentage_print(t_var *st);

static const t_fptr_print_op print_disp_tbl[10] = {
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
};

static const t_fptr_flag_op flag_disp_tbl[1] = {
	flag_plus,
};

#endif