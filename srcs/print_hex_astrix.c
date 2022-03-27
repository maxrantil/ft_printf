/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_astrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/27 16:56:30 by mrantil          ###   ########.fr       */
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
	if (*st->hold_str == '-')
	{
		if (st->plus_flag && !st->minus_flag && --st->char_count)
			st->plus_flag = OFF;
		exec_precision(st);
		exec_flag_zero(st);
		st->hold_str++;
	}
	else if (st->plus_flag)
	{
		ft_putchar('+');
		st->for_plus = ON;
		st->plus_flag = OFF;
		exec_precision(st);
	}
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
	/* if (st->hash_flag && st->width)
		st->width -= 2; */
	//st->precision -= (st->hash_flag);
	/* if (st->precision && st->zero_flag)
		st->precision += 2; */
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
	else if (st->astx_ret)
	{
		sub = st->astx_ret;
		if (st->plus_flag == ON)
			--sub;
		while (sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
	return ;
}