/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/19 18:39:09 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_width(t_var *st)
{
	int c_single;

	c_single = 0;
	if (st->zero_flag == OFF)			//maybe unnessesary??
	{
		if (ft_isdigit(*st->ptr))   //take away
		{
			while (ft_isdigit(*st->ptr) && ++c_single) ///make a function for precision and widrth together
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
