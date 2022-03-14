/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/14 18:35:53 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	pf_putstr(t_var *st)
{
	size_t len;

	len = st->len_va_arg;
	if (st->precision)
		st->len_va_arg = st->precision;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	if (!len && st->width)
	{
		while (len++ < st->precision)
			st->char_count += write(1, " ", 1);
	}
	else
	{
		if (!len)
			st->char_count += write(1, st->hold_str, len);
		else
			st->char_count += write(1, st->hold_str, st->len_va_arg);
	}
	if (st->minus_flag == ON)
		exec_width(st);
}


void	str_print(t_var *st)
{
	st->hold_str = va_arg(st->ap, char *);
	if (st->hold_str == NULL)
	{
		st->char_count += write(1, "(null)", 6);
		return ;
	}
	st->len_va_arg = ft_strlen(st->hold_str);
	asterix_print(st);
	pf_putstr(st);
}
