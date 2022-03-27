/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/27 21:05:55 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	get_it(t_var *st)
{
	size_t	c_single;
	size_t	ret;

	c_single = 0;
	ret = 0;
	++st->prec_noll;
	while (ft_isdigit(*st->fmt) && ++c_single)
	{
		if (c_single == 1 && ++c_single)
			ret = *st->fmt - 48;
		else
			ret = ret * 10 + (*st->fmt - 48);
		st->fmt++;
	}
	return (ret);
}

void	check_precision(t_var *st)
{
	if (*st->fmt == '.')
	{
		if (st->zero_flag) //new test (zero flag ignored with precision on %d)
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
	if (ft_isdigit(*st->fmt ) && (st->zero_flag == OFF || st->prec_noll == ON))
		st->width = get_it(st);
}

void	exec_precision(t_var *st)
{
	long sub;

	sub = st->precision;
	st->len_va_arg -= (st->va_ret < 0);
	//st->precision -= (st->hash_flag && *st->fmt == 'o');
	//st->precision -= 2 * (st->hash_flag && (*st->fmt == 'x' || *st->fmt == 'X'));
	if (st->precision && !st->plus_flag)
	{
		/* if (st->zero_flag) // wrong, zero glaf ignores when precision
		{
			sub =  st->zero - st->precision;
			sub *= (st->va_ret >= 0 && st->precision < st->zero);
			while (sub--)
				st->char_count += write(1, " ", 1);
			sub *= (st->zero < st->precision && st->va_ret >= 0 && st->precision < st->zero);
		} */
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, "0", 1);
	}
}

void	exec_width(t_var *st)
{
	long sub;

	sub = 0;
	sub *= (st->astx_ret);
	if (st->precision)
	{
		if (st->precision < st->len_va_arg)
		{
			st->precision = st->len_va_arg;
			st->precision -= (st->va_ret < 0);
		}
		//st->precision -= (st->hash_flag); //somthing like this
		sub += st->width - st->precision;
		sub -= (st->va_ret < 0 || st->plus_flag || st->space_count || (st->minus_flag  && st->for_plus)); //|| st->minus_flag);
		sub *= (sub > 0);
		while ((size_t)sub--)
			st->char_count += write(1, " ", 1);
	}
	else
	{
		sub -= ((st->for_plus && --st->char_count) || (st->minus_flag && st->va_ret < 0));
		sub += (st->precision_flag && !st->precision);
		sub -= (st->plus_flag || st->space_count || st->char_width);
		sub += st->width;
		sub *= (sub > 0);
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
}
