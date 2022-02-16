/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:09:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/16 20:08:59 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_precision(t_var *st)
{
	int c;

	c = 0;
	if (*st->ptr == '.')
	{
		st->precision_flag = ON;
		st->ptr++;
		while (ft_isdigit(*st->ptr) && ++c)
		{
			if (c == 1 && ++c)
				st->precision = *st->ptr - 48;
			else	
				st->precision = st->precision * 10 + (*st->ptr - 48);
			st->ptr++;
		}
	}
	return ;
}

void	exec_precision(t_var *st)
{
	int c;

	c = st->precision;
	if (st->int_ret < 0)
		--st->len_va_arg; 					//is this correcct? i think yes.
	if (st->len_va_arg && st->precision_flag == ON)
	{
			while (c-- > st->len_va_arg && ++st->char_count) // check later for width > st->len_va_arg, or simular
				ft_putchar('0');
		st->precision_flag = OFF;
	}
	return ;
}
