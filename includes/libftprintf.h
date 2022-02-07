/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/07 16:35:55 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // remove before eval

# define TABLE_POS "dicsu"

typedef struct s_var
{
	size_t		space_count;
	size_t		char_count;
}				t_var;

typedef int	(*t_print_op)(t_var *st, const char	*p, va_list	ap);

int	ft_printf(const char *restrict fmt, ...);
int	check_ptr(t_var *st, const char	*p, va_list	ap);
int	int_print(t_var *st, const char *p, va_list ap);
int	char_print(t_var *st, const char *p, va_list ap);
int	str_print(t_var *st, const char *p, va_list ap);
int	uint_print(t_var *st, const char *p, va_list ap);

static const t_print_op dispatch_table[5] = {
	int_print,
	int_print,
	char_print,
	str_print,
	uint_print
};

//int num_dispatches = sizeof(dispatch_table) / sizeof(dispatch_table[0]);
#endif