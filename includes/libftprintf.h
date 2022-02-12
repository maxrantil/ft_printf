/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 16:43:47 by mrantil          ###   ########.fr       */
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
//# define NUM_DISP sizeof(print_disp_tbl) / sizeof(print_disp_tbl[0]);

typedef enum e_conversions
{
	D = 0,
	I = 0,
	C = 2,
	S = 3,
	U = 4,
	O = 5,
	X = 6,
	BX = 7
}	t_enum_conversions;

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

int	ft_printf(const char *fmt, ...);				//*restrict?
int	int_print(t_var *st, va_list ap);
int	char_print(t_var *st, va_list ap);
int	str_print(t_var *st, va_list ap);
int	uint_print(t_var *st, va_list ap);
int	oct_print(t_var *st, va_list ap);
int	hex_print(t_var *st, va_list ap);
//int	binary_print(t_var *st, va_list ap);

/*
** Functions for flags dispatch table
*/

int	plus_flag(t_var *st, va_list ap);

/*
** Other functions
*/

int		check_str(t_var st, va_list ap);
char	*pf_itoa_base(unsigned int nbr, unsigned int base, const char *ptr);
int		procentage_print(t_var *st);

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

#endif