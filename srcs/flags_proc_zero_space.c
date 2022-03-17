/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/17 14:25:32 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	exec_flag_space(t_var *st)
{
	if (ft_isalpha(*st->fmt) && st->space_count && !st->plus_flag)
		st->char_count += write(1, " ", 1);
}

void	get_flag_space(t_var *st)
{
	while (*st->fmt == ' ' && ++st->space_count)
		st->fmt++;
}

void	exec_flag_zero(t_var *st)
{
	long	sub;

	sub = st->zero;
	sub -= (st->va_ret < 0);
	if (st->precision && st->zero_flag == ON)
		sub = st->precision - st->len_va_arg + st->len_va_arg;
	if (st->width && st->zero_flag == ON)
	{
		sub = st->width - st->len_va_arg + st->len_va_arg;
		sub -= (st->va_ret < 0);
	}
	sub -= (st->hash_flag > 0) * 2;
	sub -= (st->for_plus > 0 || st->space_count > 0);
	sub *= (sub > 0);
	while ((size_t)sub-- > st->len_va_arg)
		st->char_count += write(1, "0", 1);
	st->zero_flag = OFF;	
}

void	get_flag_zero(t_var *st)
{
	if (*st->fmt == '0')
	{
		while (*st->fmt == '0')
			st->fmt++;
		if (!st->minus_flag)
		{
			st->zero_flag = ON;
			st->zero = get_it(st);
		}	
	}
}

void	exec_flag_proc(t_var *st)
{
	size_t	i;

	i = 0;
	if (*st->fmt == '%' && st->minus_flag == OFF)
	{
		while (++i < st->width)
			st->char_count += write(1, " ", 1);
		st->char_count += write(1, st->fmt, 1);
	}
	else if (*st->fmt == '%' && st->minus_flag == ON)
	{
		st->char_count += write(1, st->fmt, 1);
		while (++i < st->width)
			st->char_count += write(1, " ", 1);
	}
	st->fmt++;
}
