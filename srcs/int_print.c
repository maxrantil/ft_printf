/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 19:34:23 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	pf_putint(int nbr, t_var *st)
{
	if (nbr < 0 && ++st->char_count)
	{
		ft_putchar('-');
		nbr *= -1;
		exec_precision(st);
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

void	int_print(t_var *st)
{
	if (st->space_count-- && ++st->char_count) /// my oold flag space code
		ft_putchar(' ');
	st->int_ret = va_arg(st->ap, int);
	st->len_va_arg = ft_intlen(st->int_ret);
	asterix_print(st);
	if (st->minus_flag == OFF)
		exec_width(st);
	if (st->int_ret >= 0)
		exec_precision(st);
	st->char_count = pf_putint(st->int_ret, st);
	if (st->minus_flag == ON)
		exec_width(st);
	return ;
}
