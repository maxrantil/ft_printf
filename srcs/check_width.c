/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/18 23:26:39 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_width(t_var *st)
{
	int c_single;

	c_single = 0;
	if (st->zero_flag == OFF) //maybe unnessesary
	{
		if (ft_isdigit(*st->ptr))
		{
			//st->width_flag = ON;
			while (ft_isdigit(*st->ptr) && ++c_single)
			{
				if (c_single == 1 && ++c_single)
					st->width = *st->ptr - 48;
				else
					st->width = st->width * 10 + (*st->ptr - 48);
				st->ptr++;
			}
		}
	}
}

void	exec_width(t_var *st)
{
	int sub;
	int c;

	sub = 0;
	c = st->width;
	if (st->len_va_arg && st->width)
	{
		if (st->precision || (!st->precision && st->minus_flag == ON))
		{
			if (st->int_ret < 0)
				sub = -1;
			sub =  sub + ft_imax(st->width, st->precision) - ft_imin(st->width, st->precision);
			sub *= (st->width > st->precision);
			sub *= (sub > 0);
			while (sub-- && ++st->char_count)
				ft_putchar(' ');
		}
		else
		{
			while (c-- > st->len_va_arg && ++st->char_count)
				ft_putchar(' ');
		}
		//st->width_flag = OFF;
	}
}
