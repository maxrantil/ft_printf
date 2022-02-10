/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 16:47:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // remove before eval

# define CHAR_CONV "dicsuoxX"
# define FLAGS "+%"
# define ON 1
# define OFF 0

typedef struct s_var
{
	const char *ptr;
	int			space_count;
	int			char_count;
	int			flag;
}				t_var;

typedef int	(*t_fptr_print_op)(t_var *st, va_list	ap);
typedef int	(*t_fptr_flag_op)(t_var *st, va_list	ap);

/*
** Functions for print dispatch table
*/

int	ft_printf(const char *fmt, ...);
int	int_print(t_var *st, va_list ap);
int	char_print(t_var *st, va_list ap);
int	str_print(t_var *st, va_list ap);
int	uint_print(t_var *st, va_list ap);
int	oct_print(t_var *st, va_list ap);
int	hex_print(t_var *st, va_list ap);

/*
** Functions for flags dispatch table
*/

int	plus_flag(t_var *st, va_list ap);

/*
** Other functions
*/

int	check_str(t_var st, va_list ap);
int	pf_intlen(unsigned int nbr, unsigned int base);
int	procentage_print(t_var *st);

static const t_fptr_print_op print_disp_tbl[8] = {
	int_print,
	int_print,
	char_print,
	str_print,
	uint_print,
	oct_print,
	hex_print,
	hex_print,
};

static const t_fptr_flag_op flag_disp_tbl[1] = {
	plus_flag
};

//int num_dispatches = sizeof(dispatch_table) / sizeof(dispatch_table[0]);
#endif