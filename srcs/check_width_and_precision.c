/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width_and_precision.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/19 23:41:40 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	get_it(t_var *st)
{
	int c_single;
	int	ret;

	c_single = 0;
	ret = 0;
	while (ft_isdigit(*st->ptr) && ++c_single)
	{
		if (c_single == 1 && ++c_single)
			ret = *st->ptr - 48;
		else
			ret = ret * 10 + (*st->ptr - 48);
		st->ptr++;
	}
	return (ret);
}

void	check_precision(t_var *st)
{
	if (*st->ptr == '.')
	{
		st->ptr++;
		st->precision = get_it(st);
	}
}

void	exec_precision(t_var *st)
{
	int sum;
	int sub;

	sum = st->precision;
	st->len_va_arg -= (st->int_ret < 0);
	if (st->len_va_arg && st->precision && st->plus_flag == OFF)
	{
			if (st->zero_flag == ON)
			{
				sub =  st->zero - st->precision;	//ft_imax(st->precision, st->zero) - ft_imin(st->precision, st->zero);
				sub *= (st->int_ret > 0 && st->precision < st->zero);
				while (sub--)
					st->char_count += write(1, " ", 1);
				sum *= (st->zero < st->precision && st->int_ret > 0 && st->precision < st->zero);
			}
			while (sum-- > st->len_va_arg)
				st->char_count += write(1, "0", 1);
	}
}

void	check_width(t_var *st)
{
	if (st->zero_flag == OFF)
		st->width = get_it(st);
}

void	exec_width(t_var *st)
{
	int sub;
	int sum;

	sum = st->width;
	if (st->len_va_arg && st->width)
	{
		if (st->precision || (!st->precision && st->minus_flag == ON))
		{
			sub = 0;
			sub -= (st->int_ret < 0);
			sub += (ft_imax(st->width, st->precision) - ft_imin(st->width, st->precision));
			sub *= (st->width > st->precision && sub > 0);
			while (sub--)
				st->char_count += write(1, " ", 1);
		}
		else
		{
			while (sum-- > st->len_va_arg)
				st->char_count += write(1, " ", 1);
		}
	}
}
