/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_astrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/29 22:16:45 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_hex_length(t_var *st)
{
	if (*st->fmt == 'x' || *st->fmt == 'X')
		pf_itoa_base((unsigned int)va_arg(st->ap, long long), 16, st);
	else if (*st->fmt == 'h' && (st->fmt[1] == 'x' || st->fmt[1] == 'X') \
		&& ++st->fmt)
		pf_itoa_base((unsigned short)va_arg(st->ap, long long), 16, st);
	else if (*st->fmt == 'l' && (st->fmt[1] == 'x' || st->fmt[1] == 'X') \
		&& ++st->fmt)
		pf_itoa_base(va_arg(st->ap, unsigned long), 16, st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'h' \
		&& (st->fmt[2] == 'x' || st->fmt[2] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, long long), 16, st);
	}
	else if (*st->fmt == 'l' && st->fmt[1] == 'l' \
		&& (st->fmt[2] == 'x' || st->fmt[2] == 'X'))
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

void	hex_print(t_var *st)
{
	st->width -= 2 * (st->hash_flag && st->width \
		&& (*st->fmt == 'x' || *st->fmt == 'X'));
	exec_flags_and_length(st);
	pf_write(st);
	if (st->minus_flag)
		exec_width(st);
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
		while (sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
		st->astx_ret = 0;
	}
}
