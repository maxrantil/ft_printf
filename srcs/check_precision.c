/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:09:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/19 18:39:49 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_precision(t_var *st)
{
	int c_single;

	c_single = 0;
	if (*st->ptr == '.')
	{
		st->ptr++;
		while (ft_isdigit(*st->ptr) && ++c_single)		///make a function for precision and widrth together
		{
			if (c_single == 1 && ++c_single)
				st->precision = *st->ptr - 48;
			else
				st->precision = st->precision * 10 + (*st->ptr - 48);
			st->ptr++;
		}
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
