/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 17:54:02 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/22 18:01:03 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_signed_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'd' || *st->fmt == 'i')
	{
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'h' && (st->fmt[i] == 'd' || st->fmt[i] == 'i'))
	{
		++st->fmt;
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && (st->fmt[i] == 'd' || st->fmt[i] == 'i'))
	{
		++st->fmt;
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' \
		&& (st->fmt[i + 1] == 'd' || st->fmt[i + 1] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' \
		&& (st->fmt[i + 1] == 'd' || st->fmt[i + 1] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
		return ;
	}
}

void	check_unsigned_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'u')
	{
		st->hold_str = \
			uint_str((unsigned int)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'u')
	{
		++st->fmt;
		st->hold_str = \
			uint_str((unsigned short)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'u')
	{
		++st->fmt;
		st->hold_str = \
			uint_str((unsigned long)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' && st->fmt[i + 1] == 'u')
	{
		st->fmt += 2;
		st->hold_str = \
			uint_str((unsigned char)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' && st->fmt[i + 1] == 'u')
	{
		st->fmt += 2;
		st->hold_str = uint_str(va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->fmt == 'L' || (*st->fmt == 'l' && st->fmt[i] == 'f')) // is this correct?
	{
		++st->fmt;
		st->le_f = ON;
	}
}

void	check_hex_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'x' || *st->fmt == 'X')
	{
		pf_itoa_base((unsigned int)va_arg(st->ap, long long), 16, st);
		return ;
	}
	else if (*st->fmt == 'h' && (st->fmt[i] == 'x' || st->fmt[i] == 'X'))
	{
		++st->fmt;
		pf_itoa_base((unsigned short)va_arg(st->ap, long long), 16, st);
		return ;
	}
	else if (*st->fmt == 'l' && (st->fmt[i] == 'x' || st->fmt[i] == 'X'))
	{
		++st->fmt;
		pf_itoa_base(va_arg(st->ap, unsigned long), 16, st);
		return ;
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' \
		&& (st->fmt[i + 1] == 'x' || st->fmt[i + 1] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base((unsigned char)va_arg(st->ap, long long), 16, st);
		return ;
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' \
		&& (st->fmt[i + 1] == 'x' || st->fmt[i + 1] == 'X'))
	{
		st->fmt += 2;
		pf_itoa_base(va_arg(st->ap, long long), 16, st);
		return ;
	}
}

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
