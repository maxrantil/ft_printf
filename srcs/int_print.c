/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/20 17:44:22 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_putint(int n, t_var *st)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0 && ++st->char_count)
	{
		if (st->plus_flag == ON && --st->char_count)
			st->plus_flag = OFF;
		/* if (st->zero_flag == ON)
				write(1, " ", 1); */
		ft_putchar('-');
		nbr *= -1;
		exec_flag_space(st);
		exec_precision(st);
		exec_flag_zero(st);
	}
	else if (st->plus_flag == ON)
	{
		st->plus_flag = OFF;
		ft_putchar('+');
		exec_precision(st);
	}
	if (nbr > 9)
	{
		pf_putint(nbr / 10, st);
		pf_putint(nbr % 10, st);
	}
	else if (++st->char_count)
		ft_putchar((char)nbr + 48);
}

void	int_print(t_var *st)
{

	st->va_ret = va_arg(st->ap, int);
	st->len_va_arg = ft_intlen(st->va_ret); //this is the part where i should redo them into a char array?
	asterix_print(st);
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	//if ((st->enum_flags[1] & MINUS) == 0)
	if (st->va_ret >= 0)
	{
		exec_flag_space(st);
		exec_precision(st);
		exec_flag_zero(st);
	}
	if (st->le_short == ON)
		pf_putint((short)st->va_ret, st);
	else if (st->le_signed_char == ON)
		pf_putint((signed char)st->va_ret, st);
/* 	else if (st->le_unsigned_char == ON)
		pf_putint((unsigned char)st->va_ret, st);
	else if (st->le_long == ON)
		pf_putint((long)st->va_ret, st);
	else if (st->le_unsigned_long == ON)
		pf_putint((unsigned long)st->va_ret, st);
	else if (st->le_long_long == ON)
		pf_putint((long long)st->va_ret, st);
	else if (st->le_unsigned_long_long == ON)
		pf_putint((unsigned long long)st->va_ret, st); */
	else
		pf_putint((int)st->va_ret, st);
	if (st->minus_flag == ON)
	{
		exec_width(st);
		//exec_flag_zero(st);
	}
	//if ((st->enum_flags[1] & MINUS) != 0)
	return ;
}
