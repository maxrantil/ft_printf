/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 14:29:17 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	pf_putint(int nbr, t_var *st)
{
	if (nbr < 0 && ++st->char_count)
	{
		ft_putchar('-');
		nbr *= -1;
		if (st->plus_flag == ON && --st->char_count)
			st->plus_flag = OFF;
	}
	else if (st->plus_flag == ON)
	{
		st->plus_flag = OFF;
		ft_putchar('+');
	}
	if (nbr > 9)
	{
		pf_putint(nbr / 10, st);
		pf_putint(nbr % 10, st);
	}
	else
	{
		ft_putchar((char)nbr + 48);
		st->char_count++;
	}
	return (st->char_count);
}

int	int_print(t_var *st)
{
	///int	int_ret;
	
	if (*st->ptr == 'd' || *st->ptr == 'i' || asterix_print(st))
	{
		if (st->space_count-- && ++st->char_count) /// my oold flag space code
			ft_putchar(' ');
		st->int_ret = va_arg(st->ap, int);
		st->len_va_arg = ft_intlen(st->int_ret);
		asterix_print(st);
		if (st->minus_flag == OFF)
			check_width(st);
		check_precision(st);
		st->char_count = pf_putint(st->int_ret, st);
		if (st->minus_flag == ON)
			check_width(st);
		return (st->char_count);
	}
	return (0);
}
