/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 19:35:41 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_width(t_var *st)
{
	int single_digit_check;

	single_digit_check = 0;
	if (ft_isdigit(*st->ptr))
	{	
		st->width_flag = ON;
		while (ft_isdigit(*st->ptr) && ++single_digit_check)
		{
			if (single_digit_check == 1 && ++single_digit_check)
				st->width = *st->ptr - 48;
			else	
				st->width = st->width * 10 + (*st->ptr - 48);
			st->ptr++;
		}
		if (*st->ptr == '.')
			check_precision(st);
	}
	return ;
}

void	exec_width(t_var *st)
{
	int sub;
	
	sub = 0;
	if (st->len_va_arg && st->width_flag == ON)							//can you shorten this into somthing cleaner?
	{
		if (st->precision_flag == ON && st->minus_flag == ON)
			check_precision(st);
		else if (st->precision_flag == ON)
		{
			if (st->int_ret < 0)
				sub = -1;
			sub =  sub + ft_imax(st->width, st->precision) - ft_imin(st->width, st->precision);
			while (sub-- && ++st->char_count)
				ft_putchar(' ');
		}
		else if (st->precision_flag == OFF && st->minus_flag == ON)
		{
			if (st->int_ret < 0)
				sub = -1;
			sub = sub + ft_imax(st->width, st->len_va_arg) - ft_imin(st->width, st->len_va_arg) - 1; // -1 here is hardcode
			while (sub-- > st->len_va_arg && ++st->char_count)
				ft_putchar(' ');
		}
		else
		{
			while (st->width-- > st->len_va_arg && ++st->char_count)
				ft_putchar(' ');
		}
		st->width_flag = OFF;
	}
	return ;
}
