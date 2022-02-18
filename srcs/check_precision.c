/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:09:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/18 16:00:32 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_precision(t_var *st)
{
	int c_single;

	c_single = 0;
	if (*st->ptr == '.')
	{
		st->precision_flag = ON;
		st->ptr++;
		while (ft_isdigit(*st->ptr) && ++c_single)
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

	sum = st->precision;
	if (st->int_ret < 0) //more checks here for 0 flags?
		--st->len_va_arg;
	if (st->len_va_arg && st->precision_flag == ON && st->plus_flag == OFF)
	{
			while (sum-- > st->len_va_arg && ++st->char_count)
				ft_putchar('0');
		st->precision_flag = OFF;
	}
}
