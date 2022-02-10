/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 15:57:15 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static t_var	initialize_st(const char *fmt)
{
	t_var	st;

	st.ptr = fmt;
	st.space_count = 0;
	st.char_count = 0;
	st.flag = OFF;
	return (st);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_var		st;

	va_start(ap, fmt);
	st = initialize_st(fmt);
	while (*st.ptr)
	{
		if (*st.ptr != '%' && ++st.char_count)
		{
			ft_putchar(*st.ptr++);
			continue ;
		}
		st.ptr++;
		while (*st.ptr == ' ' && ++st.space_count && ++st.char_count)
			st.ptr++;
		if (st.space_count > 1)
			st.char_count -= st.space_count;
		st.char_count = check_ptr(&st, ap);
		if (!st.char_count)
			return (-1);
		st.ptr++;
		st.space_count = 0;
	}
	va_end(ap);
	return (st.char_count);
}
