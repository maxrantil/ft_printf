/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:54:02 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 17:55:06 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_signed_length(t_var *st)
{
	int i;

	i = 1;
	if (*st->fmt == 'h' && (st->fmt[i] == 'd' || st->fmt[i] == 'i'))
	{
		++st->fmt;
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'u')
	{
		++st->fmt;
		st->hold_str = conv_uint_to_str((unsigned short)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' && (st->fmt[i + 1] == 'd' || st->fmt[i + 1] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'h' &&  st->fmt[i] == 'h' && st->fmt[i + 1] == 'u')
	{
		st->fmt += 2;
		st->hold_str = conv_uint_to_str((unsigned char)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'u')
	{
		st->hold_str = conv_uint_to_str((unsigned int)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'd' || *st->fmt == 'i')
	{
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);
		return ;
	}
}

void	check_unsigned_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'l' && (st->fmt[i] == 'd' || st->fmt[i] == 'i'))
	{
		++st->fmt;
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'u')
	{
		++st->fmt;
		st->hold_str = conv_uint_to_str((unsigned long)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' &&(st->fmt[i + 1] == 'd' || st->fmt[i + 1] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' && st->fmt[i + 1] == 'u')
	{
		st->fmt += 2;
		st->hold_str = conv_uint_to_str((unsigned long long)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'L')
	{
		++st->fmt;
		st->le_F = ON;
	}
}