/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 11:26:54 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static t_var	initialize_st(const char *fmt)
{
	t_var	st;

	st.ptr = (char *)fmt;
	st.space_count = 0;
	st.char_count = 0;
	st.astx_ret = 0;
	st.len_va_arg = 0;
	st.flag = OFF;
	return (st);
}

int	ft_printf(const char *fmt, ...)
{
	va_list		ap;
	t_var		st;

	va_start(ap, fmt);
	st = initialize_st(fmt);
	st.char_count = parser_loop(st, ap);
	va_end(ap);
	return (st.char_count);
}
