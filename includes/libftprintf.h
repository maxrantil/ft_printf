/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:06:19 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 09:45:26 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

# include <stdio.h> // remove before eval

# define TABLE_POS "dicsu"
# define DEC 0
# define INT 1
# define CHAR 2
# define STR 3
# define UINT 4

typedef struct s_var
{
	size_t		space_count;
	size_t		char_count;
}				t_var;

typedef int	(*t_fptr_print_op)(t_var *st, const char	*p, va_list	ap);

int	ft_printf(const char *restrict fmt, ...);
int	check_ptr(t_var *st, const char	*p, va_list	ap);

int	int_print(t_var *st, const char *p, va_list ap);
int	char_print(t_var *st, const char *p, va_list ap);
int	str_print(t_var *st, const char *p, va_list ap);
int	uint_print(t_var *st, const char *p, va_list ap);


//int num_dispatches = sizeof(dispatch_table) / sizeof(dispatch_table[0]);
#endif