/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:09:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/18 22:00:20 by mrantil          ###   ########.fr       */
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
	int sub;

	sum = st->precision;
	if (st->int_ret < 0) 				//possible with one line???
		--st->len_va_arg;
	//st->int_ret -= (st->int_ret < 0); //a try to make it to one line without success, time to call it a night now
	if (st->len_va_arg && st->precision_flag == ON && st->plus_flag == OFF)
	{
			if (st->zero_flag == ON)
			{
				sub = ft_imax(st->precision, st->zero) - ft_imin(st->precision, st->zero);
				if (st->int_ret < 0 || st->precision > st->zero)													//make this into one line??
					sub = 0;
				while (sub--)
				{
					write(1, " ", 1);
					++st->char_count;
				}
				if (st->zero > st->precision || st->int_ret < 0 || st->precision > st->zero)
					sum = 0;
				
			}
			while (sum-- > st->len_va_arg && ++st->char_count)
				ft_putchar('0');
		st->precision_flag = OFF;
	}
}
