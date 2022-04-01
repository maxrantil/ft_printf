/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_astrix_procent.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/01 14:17:07 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_hex_length(t_var *st)
{
	if (*st->fmt == 'x' || *st->fmt == 'X')
		pf_itoa_base((unsigned int)va_arg(st->ap, unsigned long long), 16, st);
	else if (*st->fmt == 'h' && (st->fmt[1] == 'x' || st->fmt[1] == 'X') \
		&& ++st->fmt)
		pf_itoa_base((unsigned short)va_arg(st->ap, unsigned long long), 16, st);
	else if (*st->fmt == 'l' && (st->fmt[1] == 'x' || st->fmt[1] == 'X') \
		&& ++st->fmt)
		pf_itoa_base(va_arg(st->ap, unsigned long), 16, st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'h' \
		&& (st->fmt[2] == 'x' || st->fmt[2] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, unsigned long long), 16, st);
	}
	else if (*st->fmt == 'l' && st->fmt[1] == 'l' \
		&& (st->fmt[2] == 'x' || st->fmt[2] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base(va_arg(st->ap, unsigned long long), 16, st);
	}
}

void	pf_print_hex_hash(t_var *st)
{
	if (*st->fmt == 'x')
		st->char_count += write(1, "0x", 2);
	else
		st->char_count += write(1, "0X", 2);
}

void	hex_print(t_var *st)
{
	if (st->zero_flag && st->precision_flag)
		ignore_zero_flag(st);
	st->width -= 2 * (st->hash_flag && st->width \
		&& (*st->fmt == 'x' || *st->fmt == 'X'));
	exec_flags_and_length(st);
	pf_write(st);
	if (st->minus_flag)
		exec_width(st);
	if (st->astx_ret)
		asterix_print(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}

void	asterix_print(t_var *st)
{
	size_t	sub;

	if (*st->fmt == '*')
	{
		st->astx_ret = va_arg(st->ap, int);
		st->fmt++;
		check_parser(st);
	}
	else
	{
		sub = st->astx_ret;
		if (st->for_plus || (st->plus_flag && st->va_ret >= 0) \
			|| (st->minus_flag && st->va_ret < 0))
		{
			if (st->for_plus && st->va_ret >= 0)
				st->char_count++;
			else if (st->minus_flag && st->va_ret < 0)
				st->char_count--;
			sub--;
		}
		if (st->precision_flag)
		{
			st->precision = sub;
			return ;
		}
		else if (st->width_check)
		{
			st->width = sub;
			return ;
		}
		else
		{
			while (sub-- > st->len_va_arg)
				st->char_count += write(1, " ", 1);
			st->astx_ret = 0;
		}
	}
}

void	print_procent(t_var *st)
{
	if (st->zero_flag && st->precision_flag)
		ignore_zero_flag(st);
	if (st->plus_flag && --st->char_count)
		st->plus_flag = 0;
	st->len_va_arg = 1;
	if (st->astx_ret && !st->minus_flag)
		asterix_print(st);
	else if (!st->minus_flag && st->width && !st->zero_flag)
		exec_width(st);
	if (ft_isalpha(*st->fmt) \
		&& st->space_count && !st->plus_flag)
		exec_flag_space(st);
	if (st->precision_flag)
		exec_precision(st);
	if (!st->plus_flag && st->zero_flag && !st->precision_flag)
		exec_flag_zero(st);
	st->char_count += write(1, st->fmt, 1);
	if (st->minus_flag)
		exec_width(st);
	if (st->astx_ret)
		asterix_print(st);
	st->fmt++;
}
