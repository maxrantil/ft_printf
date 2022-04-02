/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null_float_oct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/02 16:21:58 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	null_print(t_var *st)
{
	st->sign = 0;
}

void	pf_putfloat(t_var *st)
{
	pf_exec_before_flags(st);
	if (st->sign < 0)
		st->char_count += write(1, "-", 1);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->hash_flag && !st->precision && st->precision_flag)
		st->char_count += write(1, ".", 1);
}

void	float_print(t_var *st)
{
	if (!st->precision_flag)
		st->precision = 6;
	if (st->le_f)
		conv_float_str(va_arg(st->ap, long double), st);
	else
		conv_float_str(va_arg(st->ap, double), st);
	exec_flags_and_length(st);
	pf_putfloat(st);
	if (st->minus_flag)
		exec_width(st);
	/* if (st->astx_ret)
		asterix_print(st); */
	ft_strdel(&st->hold_str);
	st->fmt++;
}

void	check_oct_length(t_var *st)
{
	if (*st->fmt == 'o')
		pf_itoa_base((unsigned int)va_arg(st->ap, unsigned long long), 8, st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'o' && ++st->fmt)
		pf_itoa_base((unsigned short)va_arg(st->ap, unsigned long long), 8, st);
	else if (*st->fmt == 'l' && st->fmt[1] == 'o' && ++st->fmt)
		pf_itoa_base((unsigned long)va_arg(st->ap, unsigned long long), 8, st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'h' && st->fmt[2] == 'o')
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, unsigned long long), 8, st);
	}
	else if (*st->fmt == 'l' && st->fmt[1] == 'l' && st->fmt[2] == 'o')
	{
		st->fmt += 2;
		pf_itoa_base(va_arg(st->ap, unsigned long long), 8, st);
	}
	else if ((*st->fmt == 'L' || (*st->fmt == 'l' && st->fmt[1] == 'f')))
	{
		if (*st->fmt == 'L')
			st->le_f = 1;
		++st->fmt;
	}
}

void	ignore_zero_flag(t_var *st)
{
	st->zero_flag = 0;
	st->width = st->zero;
	st->zero = 0;
}

void	oct_print(t_var *st)
{
	if (st->zero_flag && st->precision_flag)
		ignore_zero_flag(st);
	exec_flags_and_length(st);
	pf_write(st);
	if (st->minus_flag)
		exec_width(st);
	/* if (st->astx_ret)
		asterix_print(st); */
	ft_strdel(&st->hold_str);
	st->fmt++;
}
