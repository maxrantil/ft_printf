/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 16:56:56 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	initialize_st(const char *fmt, t_var *st)
{
	st->ptr = fmt;
	st->space_count = 0;
	st->char_count = 0;
	st->astx_ret = 0;
	st->len_va_arg = 0;
	st->width_flag = OFF;
	st->precision_flag = OFF;
	st->plus_flag = OFF;
	st->minus_flag = OFF;
	st->width = 0;
	st->int_ret = 0; // unnessasary?
	st->unnessesary = 0; // unnessasary?
	//st->enum_flags[0] = ERROR;
	/* st->enum_flags[0] = ERROR; */
}

int	ft_printf(const char *fmt, ...)
{
	t_var		st;

	va_start(st.ap, fmt);
	initialize_st(fmt, &st);
	st.char_count = parser_loop(st);
	va_end(st.ap);
	return (st.char_count);
}
