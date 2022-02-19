/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/19 18:32:37 by mrantil          ###   ########.fr       */
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
	st->width = 0;
	st->precision = 0;						//is it nessesary to init to 0?????
	st->plus_flag = OFF;
	st->minus_flag = OFF;
	st->int_ret = 0; 						//change this later to not only int and cast it to anything?
	st->unnessesary = 0;					// unnessasary?
	st->le_short = OFF;
	st->le_signed_char = OFF;
	st->le_unsigned_short = OFF;
	st->hash_flag = OFF;
	st->zero = 0;
	st->zero_count = 0;
	st->zero_flag = OFF;
/* 	st->enum_flags[0] = 0;
	st->enum_flags[1] = 0;
	st->enum_flags[2] = 0; */
}

int	ft_printf(const char *fmt, ...)
{
	t_var		st;

	va_start(st.ap, fmt);
	initialize_st(fmt, &st);
	parser_loop(&st);
	va_end(st.ap);
	return (st.char_count);
}
