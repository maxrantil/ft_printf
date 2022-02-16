/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/16 20:19:08 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_width(t_var *st)
{
	int c;

	c = 0;
	if (ft_isdigit(*st->ptr))
	{	
		st->width_flag = ON;
		while (ft_isdigit(*st->ptr) && ++c)
		{
			if (c == 1 && ++c)
				st->width = *st->ptr - 48;
			else	
				st->width = st->width * 10 + (*st->ptr - 48);
			st->ptr++;
		}
		//if (*st->ptr == '.')
			//check_precision(st);
	}
	return ;
}

void	exec_width(t_var *st)
{
	int sub;
	int c;
	
	sub = 0;
	c = st->width;
	if (st->len_va_arg && st->width_flag == ON)		//this is allways true? can take it away//can you shorten this into somthing cleaner?
	{
		if (st->precision_flag == ON)
		{
			if (st->int_ret < 0)
				sub = -1;
			sub =  sub + ft_imax(st->width, st->precision) - ft_imin(st->width, st->precision);
			if (sub < 0) 	//make this to one line
				sub = 0;
			while (sub-- && ++st->char_count) // > st->len_va_arg  ??? or not
				ft_putchar(' ');
		}
		else if (st->precision_flag == OFF && st->minus_flag == ON)
		{
			if (st->int_ret < 0)
				sub = -1;
			sub = sub + ft_imax(st->width, st->precision) - ft_imin(st->width, st->precision);
			if (sub < 0) 	//make this to one line
				sub = 0;
			while (sub-- && ++st->char_count)
				ft_putchar(' ');
		}
		else
		{
			while (c-- > st->len_va_arg && ++st->char_count)
				ft_putchar(' ');
		}
		st->width_flag = OFF;
	}
	return ;
}
