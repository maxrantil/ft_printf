/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/13 13:00:45 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	pf_putstr(t_var *st)
{
	size_t len;

	len = st->len_va_arg;
	/* if (*st->hold_str == '-')
	{
		if (st->plus_flag == ON && st->minus_flag == OFF && --st->char_count)
			st->plus_flag = OFF;
		//exec_flag_space(st);
		exec_precision(st);
		exec_flag_zero(st);
		st->hold_str++;
	} */
	/* else if (st->plus_flag == ON)
	{
		ft_putchar('+');
		st->for_plus = ON;
		st->plus_flag = OFF;
		exec_precision(st);
	} */
	if (st->precision)
		st->len_va_arg = st->precision;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	if (!len)
	{
		while (len++ < st->precision)
			st->char_count += write(1, " ", 1);
	}
	else
		st->char_count += write(1, st->hold_str, st->len_va_arg);
	/* else
		st->char_count += write(1, "", 0); */
	if (st->minus_flag == ON)
		exec_width(st);
}


void	str_print(t_var *st)
{
	st->hold_str = va_arg(st->ap, char *);
	st->len_va_arg = ft_strlen(st->hold_str);
	asterix_print(st);
	pf_putstr(st);
}
