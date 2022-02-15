/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:09:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 14:31:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	check_precision(t_var *st)
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
				st->precision = st->width * 10 + (*st->ptr - 48);
			st->ptr++;
		}
		return (check_parser(st));
	}
	if (st->len_va_arg && st->precision_flag == ON)
	{
		if (st->minus_flag == ON)
		{
			while (st->precision-- > st->len_va_arg && ++st->char_count)			//need fixing ....??....???...
			{
				ft_putchar('0');
				//st->minus_flag = OFF;
				//st->precision_flag = OFF;
				//check_width(st);
			}
		}
		else
		{
			while (st->precision-- > st->len_va_arg && ++st->char_count) // check later for width > st->len_va_arg, or simular
				ft_putchar('0');
		}
		st->precision_flag = OFF;
		//check_width(st);
	}
	return (0);
}
