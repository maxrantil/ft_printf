/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 21:58:59 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_putint(int nbr, t_var *st)
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
		ft_putchar('+');
		st->flag = OFF;
	}
	if (nbr > 9)
	{
		pf_putint(nbr / 10, st);
		pf_putint(nbr % 10, st);
	}
	else
	{
		ft_putchar(*ft_itoa(nbr));
		st->char_count++;
	}
	return (st->char_count);
}

int	int_print(t_var *st, va_list ap)
{
	if (st->flag == ON)
	{
		st->ptr++;
	}
	if (*st->ptr == 'd' || *st->ptr == 'i')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		return (st->char_count = pf_putint(va_arg(ap, int), st));
	}
	return (0);
}
