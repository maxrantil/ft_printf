/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/07 14:45:16 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	initialize_st(const char *format, t_var *st)
{
	st->fmt = format;
	st->space_count = 0;
	st->char_count = 0;
	st->astx_ret = 0;
	st->len_va_arg = 0;
	st->width = 0;
	st->precision = 0;						//is it nessesary to init to 0?????
	st->plus_flag = OFF;
	st->minus_flag = OFF;
	st->va_ret = 0; 						//change this later to not only int and cast it to anything?
	st->unnessesary = 0;					// unnessasary?
	st->hash_flag = OFF;
	st->zero = 0;
	st->zero_count = 0;
	st->zero_flag = OFF;
	st->hold_str = NULL;					//can memset the whole struct to 0, try that later, also i dont need ptr and can use fmt directly
}

int	ft_printf(const char *format, ...)
{
	t_var		st;

	va_start(st.ap, format);
	initialize_st(format, &st);
	parser_loop(&st);
	va_end(st.ap);
	return ((int)st.char_count); //will it return -1 on fail? then the cast wont work...
}
