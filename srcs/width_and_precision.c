/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/01 17:22:09 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_precision(t_var *st)
{
	int hold;

	hold = 0;
	if (*st->fmt == '.')
	{
		st->precision_flag = 1;
		st->fmt++;
		if (*st->fmt == '*')
		{
			hold = va_arg(st->ap, int);
			if (hold < 0)
			{
				hold  *= -1;
				st->astx_ret = 1;
				st->precision = hold;
			}
			else
				st->precision = hold;	
			st->fmt++;
		}	
		else
			st->precision = get_it(st);
	}
}

void	check_width(t_var *st)
{
	int hold;

	hold = 0;
	if (*st->fmt == '*')
	{
		hold = va_arg(st->ap, int);
		if (hold < 0)
		{
			st->width_check = 1;
			hold  *= -1;
			st->minus_flag = 1;
			st->width = hold;
		}
		else
			st->width = hold;	
		st->fmt++;
	}
	else if (ft_isdigit(*st->fmt) && (!st->zero_flag || st->width_check))
		st->width = get_it(st);
}

void	exec_precision(t_var *st)
{
	long	sub;

	sub = st->precision;
	if (st->precision && !st->plus_flag && *st->fmt != '%')
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
		sub -= (st->for_plus > 0);
		sub += (st->precision_flag && !st->precision && st->astx_ret != 1);
		sub -= ((st->plus_flag > 0 && st->va_ret > 0) || st->space_count > 0 || st->char_width > 0);
		sub += st->width;
		if (*st->fmt == 'f' && st->precision_flag && !st->precision)
			sub--;
		sub *= (sub > 0);
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
}
