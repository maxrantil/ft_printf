/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/29 22:16:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	exec_precision_str(t_var *st)
{
	long	sub;

	sub = st->precision;
	if (st->precision)
	{
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, "0", 1);
	}
}

void	str_precision_width(t_var *st)
{
	long	sub;

	sub = 0;
	sub *= (st->astx_ret);
	if (st->precision && !st->width)
	{
		if (st->precision < st->len_va_arg)
			st->precision = st->len_va_arg;
		sub += st->width - st->precision;
		sub *= (sub > 0);
		while (sub--)
			st->char_count += write(1, " ", 1);
	}
	else if (st->width)
	{
		sub += st->width;
		sub *= (sub > 0);
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
}

static void	pf_write_str(t_var *st)
{
	if (st->precision && st->precision < st->len_va_arg)
		st->len_va_arg = st->precision;
	if (!st->minus_flag)
		str_precision_width(st);
	if (!st->precision && st->precision_flag)
		st->char_count += write(1, "", 0);
	else
		st->char_count += write(1, st->hold_str, st->len_va_arg);
	if (st->minus_flag)
		str_precision_width(st);
}

void	str_print(t_var *st)
{
	st->hold_str = va_arg(st->ap, char *);
	if (st->hold_str == NULL)
		st->hold_str = "(null)";
	st->len_va_arg = ft_strlen(st->hold_str);
	if ((!st->precision && st->precision_flag) && st->width)
	{
		while (st->width--)
			st->char_count += write(1, " ", 1);
		st->fmt++;
		return ;
	}
	if (st->astx_ret && !st->minus_flag)
		asterix_print(st);
	pf_write_str(st);
	if (st->astx_ret)
		asterix_print(st);
	st->fmt++;
}

void	char_print(t_var *st)
{
	st->char_width = 1;
	if (!st->minus_flag && st->width)
		exec_width(st);
	ft_putchar((char)va_arg(st->ap, int));
	++st->char_count;
	if (st->minus_flag)
		exec_width(st);
	st->fmt++;
}
