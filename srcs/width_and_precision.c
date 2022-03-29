/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/29 22:18:20 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_precision(t_var *st)
{
	if (*st->fmt == '.')
	{
		if (st->zero_flag)
		{
			st->zero_flag = 0;
			st->width = st->zero;
			st->zero = 0;
		}
		st->fmt++;
		st->precision_flag = 1;
		st->precision = get_it(st);
	}
}

void	check_width(t_var *st)
{
	if (ft_isdigit(*st->fmt) && (!st->zero_flag || st->width_check))
		st->width = get_it(st);
}

void	exec_precision(t_var *st)
{
	long	sub;

	sub = st->precision;
	if (st->precision && !st->plus_flag)
	{
		sub += (st->va_ret < 0);
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, "0", 1);
	}
}

static void	pf_exec_precision_with_width(t_var *st)
{
	long	sub;

	sub = 0;
	if (st->precision < st->len_va_arg)
	{
		sub += st->width - st->len_va_arg;
		sub += (st->va_ret < 0);
	}
	else
		sub += st->width - st->precision;
	sub -= (st->va_ret < 0 || st->plus_flag || st->space_count \
		|| (st->minus_flag && st->for_plus));
	sub *= (sub > 0);
	while (sub--)
		st->char_count += write(1, " ", 1);
}

void	exec_width(t_var *st)
{
	long	sub;

	sub = 0;
	if (st->precision)
		pf_exec_precision_with_width(st);
	else
	{
		sub -= (st->for_plus > 0 && --st->char_count);
		sub += (st->precision_flag && !st->precision);
		sub -= (st->plus_flag || st->space_count || st->char_width);
		sub += st->width;
		if (*st->fmt == 'f' && st->precision_flag && !st->precision)
			sub--;
		sub *= (sub > 0);
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
}
