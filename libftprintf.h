/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/04 17:19:16 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# include <stdio.h> // remove before eval

//# define CHECK(ST, P, AP) (P == 'd' ? int_print : 0)
/* typedef enum s_antiloop
{
	d = 'd',
	i = 'i',
	c = 'c',
	s = 's'
}			t_antiloop;  */

# define INT 0
# define CHAR 1
# define STR 2

typedef struct s_var
{
	size_t		count;
	size_t		char_counter;
}				t_var;

typedef int	(*t_disp_tbl)(t_var st, const char	*p, va_list	ap);

int	ft_printf(const char *restrict fmt, ...);

int	int_print(t_var st, const char *p, va_list ap);
int	char_print(t_var st, const char *p, va_list ap);
int	str_print(t_var st, const char *p, va_list ap);

static const t_disp_tbl dispatch_table[3] = {
	int_print,
	char_print,
	str_print
};

//int num_dispatches = sizeof(dispatch_table) / sizeof(dispatch_table[0]);
#endif