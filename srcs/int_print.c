/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:58:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	pf_putint(int nbr, t_var *st)
{
	if (nbr < 0 && ++st->char_count)
	{
		ft_putchar('-');
		nbr *= -1;
		if (st->flag == ON && --st->char_count)
			st->flag = OFF;
	}
	else if (st->flag == ON)
	{
		st->flag = OFF;
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
	int	int_ret;
	
	if (*st->ptr == 'd' || *st->ptr == 'i' || asterix_print(st))
	{
		if (st->space_count-- && ++st->char_count) /// my oold flag space code
			ft_putchar(' ');
		int_ret = va_arg(st->ap, int);
		st->len_va_arg = ft_intlen(int_ret);
		asterix_print(st);
		check_width(st);
		return (st->char_count = pf_putint(int_ret, st));
	}
	return (0);
}
