/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/14 18:50:51 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	initialize_st(const char *format, t_var *st, int flag)
{
	st->fmt = format;
	if (!flag)
	{
		st->char_count = 0;
		st->even_procent = 0;
	}
	st->space_count = 0; // this is wrong
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
	st->le_F = OFF;
	st->prec_noll = 0;
	st->for_plus = OFF;
	st->precision_zero = 0;
	st->char_width = 0;
}

int	ft_printf(const char *format, ...)
{
	t_var		st;

	va_start(st.ap, format);
	initialize_st(format, &st, 0);
	parser_loop(&st);
	va_end(st.ap);
	return ((int)st.char_count); //will it return -1 on fail? then the cast wont work...
}
