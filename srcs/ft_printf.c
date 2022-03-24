/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:46:14 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/24 19:45:36 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	initialize_st(const char *format, t_var *st, int flag)
{
	st->fmt = format;
	if (!flag)
		st->char_count = 0;
	st->space_count = 0;
	st->astx_ret = 0;
	st->len_va_arg = 0;
	st->width = 0;
	st->precision = 0;
	st->plus_flag = OFF;
	st->minus_flag = OFF;
	st->va_ret = 0;
	st->unnessesary = 0;
	st->hash_flag = OFF;
	st->zero = 0;
	st->zero_count = 0;
	st->zero_flag = OFF;
	st->hold_str = NULL;
	st->le_f = OFF;
	st->prec_noll = 0;
	st->for_plus = OFF;
	st->precision_zero = 0;
	st->char_width = 0;
	st->uint_check = OFF;
	st->sign = 1;
}

void	check_parser(t_var *st)
{
	size_t	i;

	i = 0;
	while (FLAGS[i])
	{
		while (FLAGS[i] && FLAGS[i] != *st->fmt)
			i++;
		flag_disp_tbl[i](st);
		if (st->unnessesary == 1)
			break ;
		i = 0;
	}
	i = 0;
	while (i < NUM_CHECK_DISP)
		check_disp_tbl[i++](st);
	i = 0;
	while (SPECIF[i] && SPECIF[i] != *st->fmt)
		i++;
	print_disp_tbl[i](st);
}

void	parser_loop(t_var *st)
{
	while (*st->fmt)
	{
		if (*st->fmt != '%')
		{
			st->char_count += write(1, st->fmt++, 1);
			continue ;
		}
		++st->fmt;
		check_parser(st);
		initialize_st(st->fmt, st, 1);
	}
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
