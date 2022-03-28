/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_null_float_oct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/28 09:54:56 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_print(t_var *st)
{
	st->unnessesary = 1;
	return ;
}

void	float_print(t_var *st)
{
	int		flag = 6;

	if (st->prec_noll)
		flag = st->precision;
	if (st->le_f)
		conv_float_str(va_arg(st->ap, long double), flag, st);
	else
		conv_float_str(va_arg(st->ap, double), flag, st);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	ft_strdel(&st->hold_str);
	st->fmt++;
}

void	check_oct_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'o')
		pf_itoa_base((unsigned int)va_arg(st->ap, long long), 8, st);
	else if (*st->fmt == 'h' && st->fmt[i] == 'o')
	{
		++st->fmt;
		pf_itoa_base((unsigned short)va_arg(st->ap, long long), 8, st);
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'o')
	{
		++st->fmt;
		pf_itoa_base((long)va_arg(st->ap, long long), 8, st);
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' && st->fmt[i + 1] == 'o')
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, long long), 8, st);
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' && st->fmt[i + 1] == 'o')
	{
		st->fmt += 2;
		pf_itoa_base(va_arg(st->ap, long long), 8, st);
	}
}

void	oct_print(t_var *st)
{
	//st->len_va_arg += (st->hash_flag && *st->fmt == 'o');
	exec_flags_and_length(st);
	if (*st->hold_str == '0' && st->precision_flag && !st->precision \
		&& !st->hash_flag && st->fmt++)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}
