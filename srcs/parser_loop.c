/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/07 16:19:40 by mrantil          ###   ########.fr       */
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

void	check_parser(t_var *st)
{
	size_t	i;

	i = 0;
	while (FLAGS[i])
	{
		while (FLAGS[i] && FLAGS[i] != *st->fmt)
			i++;
		flag_disp_tbl[i](st);
	}
	i = 0;
	while (i < NUM_CHECK_DISP)
		check_disp_tbl[i++](st);
	i = 0;
	while (SPECIF[i] && SPECIF[i] != *st->fmt)
		i++;
	print_disp_tbl[i](st);
}

void	parser_loop(t_var *st)
{
	while (*st->fmt)
	{
		if (*st->fmt != '%')
		{
			st->char_count += write(1, st->fmt++, 1);
			continue ;
		}
		if (*++st->fmt == '%' || *st->fmt == ' ')
		{
			while (*st->fmt == ' ' && ++st->space_count)
				st->fmt++;
			if (*st->fmt == '%')
				st->char_count += write(1, st->fmt++, 1);
			if (!ft_isalpha(*st->fmt))
				continue ;
		}
		check_parser(st);
		st->fmt++;
		st->space_count = 0;
	}
}

//error handling for only one % with nothing after.