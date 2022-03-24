/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/24 17:53:32 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_oct_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'o')
	{
		pf_itoa_base((unsigned int)va_arg(st->ap, long long), 8, st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'o')
	{
		++st->fmt;
		pf_itoa_base((unsigned short)va_arg(st->ap, long long), 8, st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'o')
	{
		++st->fmt;
		pf_itoa_base((long)va_arg(st->ap, long long), 8, st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' && st->fmt[i + 1] == 'o')
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, long long), 8, st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' && st->fmt[i + 1] == 'o')
	{
		st->fmt += 2;
		pf_itoa_base(va_arg(st->ap, long long), 8, st);
		return ;
	}
}

void	oct_print(t_var *st)
{
	st->width -= (st->hash_flag && st->width);
	exec_flags_and_length(st);
	if (st->hash_flag == ON && st->width)
		st->char_count += write(1, "0", 1);
	if (*st->hold_str == '0' && st->precision_zero && !st->precision \
		&& !st->hash_flag && st->fmt++)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}
