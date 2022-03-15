/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_and_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/15 18:47:09 by mrantil          ###   ########.fr       */
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
		st->fmt++;
		st->precision_zero = 1;
		st->precision = get_it(st);
	}
}

void	check_width(t_var *st)
{															//maybe done with isdigit, but check do a better check here so it doesnt allways go in here
	if (ft_isdigit(*st->fmt ) && (st->zero_flag == OFF || st->prec_noll == ON))
		st->width = get_it(st);
}

void	exec_precision(t_var *st)
{
	long sum;
	long sub; //make one variable??

	sum = st->precision;
	st->len_va_arg -= (st->va_ret < 0);
	if (st->precision && st->plus_flag == OFF)
	{
			if (st->zero_flag == ON)
			{
				sub =  st->zero - st->precision;	//ft_imax(st->precision, st->zero) - ft_imin(st->precision, st->zero);
				sub *= (st->va_ret >= 0 && st->precision < st->zero);
				while (sub--)
					st->char_count += write(1, " ", 1);
				sum *= (st->zero < st->precision && st->va_ret > 0 && st->precision < st->zero);
			}
			while ((size_t)sum-- > st->len_va_arg)
				st->char_count += write(1, "0", 1);
	}
}

void	exec_width(t_var *st)
{
	long sub;

	sub = 0;
	
	if (st->precision)
	{
		sub -= (st->va_ret < 0 || st->plus_flag || st->space_count); //|| st->minus_flag);
		if (st->precision < st->len_va_arg)
			st->precision = st->len_va_arg;
		sub += st->width - st->precision;
		if (st->minus_flag && st->for_plus)
			--sub;
		sub *= (sub > 0);
		while ((size_t)sub--)
			st->char_count += write(1, " ", 1);
	}
	else
	{
		if (st->for_plus && --st->char_count)
			--sub;
		if (st->minus_flag && st->va_ret < 0)
			--sub;
		sub += (st->precision_zero && !st->precision);
		sub -= (st->plus_flag || st->space_count || st->char_width);// || st->minus_flag);st->va_ret < 0 || 
		sub += st->width;
		//sub -= (st->minus_flag > 0);
		sub *= (sub > 0);
		while ((size_t)sub-- > st->len_va_arg)
			st->char_count += write(1, " ", 1);
	}
}
