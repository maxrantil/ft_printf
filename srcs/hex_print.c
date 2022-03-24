/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/24 18:17:13 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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
		if (st->plus_flag == ON && st->minus_flag == OFF && --st->char_count)
			st->plus_flag = OFF;
		exec_precision(st);
		exec_flag_zero(st);
		st->hold_str++;
	}
	else if (st->plus_flag == ON)
	{
		ft_putchar('+');
		st->for_plus = ON;
		st->plus_flag = OFF;
		exec_precision(st);
	}
	if (st->hash_flag == ON && *st->hold_str != '0' && st->width)
		pf_print_hex_hash(st);
	if (*st->hold_str == '0' && st->precision_zero && !st->precision)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
}

void	hex_print(t_var *st)
{
	if (st->hash_flag && st->width)
		st->width -= 2;
	if (st->precision && st->zero_flag)
		st->precision += 2;
	exec_flags_and_length(st);
	pf_put_hex(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}
