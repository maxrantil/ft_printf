/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_astrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/28 21:54:20 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_hex_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'x' || *st->fmt == 'X')
		pf_itoa_base((unsigned int)va_arg(st->ap, long long), 16, st);
	else if (*st->fmt == 'h' && (st->fmt[i] == 'x' || st->fmt[i] == 'X'))
	{
		++st->fmt;
		pf_itoa_base((unsigned short)va_arg(st->ap, long long), 16, st);
	}
	else if (*st->fmt == 'l' && (st->fmt[i] == 'x' || st->fmt[i] == 'X'))
	{
		++st->fmt;
		pf_itoa_base(va_arg(st->ap, unsigned long), 16, st);
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' \
		&& (st->fmt[i + 1] == 'x' || st->fmt[i + 1] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, long long), 16, st);
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' \
		&& (st->fmt[i + 1] == 'x' || st->fmt[i + 1] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base(va_arg(st->ap, long long), 16, st);
	}
}

void	pf_print_hex_hash(t_var *st)
{
	if (*st->fmt == 'x')
		st->char_count += write(1, "0x", 2);
	else
		st->char_count += write(1, "0X", 2);
}

static void	pf_put_hex(t_var *st)
{
	pf_exec_before_flags(st);
/* 	if (st->hash_flag && *st->hold_str != '0' && !st->width) //!widht is that correct?
		pf_print_hex_hash(st); */
	if (*st->hold_str == '0' && st->precision_flag && !st->precision)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag)
		exec_width(st);
}

void	hex_print(t_var *st)
{
	st->width -= 2 * (st->hash_flag && st->width && (*st->fmt == 'x' || *st->fmt == 'X'));
	exec_flags_and_length(st);
	pf_put_hex(st);
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
		if (st->for_plus || st->minus_flag)
		{
			sub--;
		}
		while (sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
}