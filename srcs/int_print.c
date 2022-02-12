/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 22:28:49 by mrantil          ###   ########.fr       */
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
		ft_putchar((char)nbr + 48);
		st->char_count++;
	}
	return (st->char_count);
}

int	int_print(t_var *st, va_list ap)
{
	int	len;
	int	astx_ret;
	int	int_ret;
	
	if (*st->ptr == 'd' || *st->ptr == 'i' || *st->ptr == '*')
	{
		if (*st->ptr == '*')
		{
			astx_ret = va_arg(ap, int); // put this into the struct and use it later in the print_func
			int_ret = va_arg(ap, int);
			len = ft_intlen((long)int_ret);
			while (astx_ret-- > len && ++st->char_count)
				ft_putchar(' ');
			st->ptr++;
			return (st->char_count = pf_putint(int_ret, st)); //duble code
		}
		/* if (st->space_count-- && ++st->char_count) /// my oold flag space code
			ft_putchar(' '); */
		else
			return (st->char_count = pf_putint(va_arg(ap, int), st));
	}
	return (0);
}
