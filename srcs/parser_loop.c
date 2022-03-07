/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/07 13:59:42 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_signed_length(t_var *st)
{
	int i;

	i = 1;
	if (*st->ptr == 'h' && (st->ptr[i] == 'd' || st->ptr[i] == 'i'))
	{
		++st->ptr;
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->ptr == 'h' && st->ptr[i] == 'u')
	{
		++st->ptr;
		st->hold_str = conv_uint_to_str((unsigned short)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->ptr == 'h' && st->ptr[i] == 'h' && (st->ptr[i + 1] == 'd' || st->ptr[i + 1] == 'i'))
	{
		st->ptr += 2;
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->ptr == 'h' &&  st->ptr[i] == 'h' && st->ptr[i + 1] == 'u')
	{
		st->ptr += 2;
		st->hold_str = conv_uint_to_str((unsigned char)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->ptr == 'u')
	{
		st->hold_str = conv_uint_to_str((unsigned int)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->ptr == 'd' || *st->ptr == 'i')
	{
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);
		return ;
	}
}

void	check_unsigned_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->ptr == 'l' && (st->ptr[i] == 'd' || st->ptr[i] == 'i'))
	{
		++st->ptr;
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->ptr == 'l' && st->ptr[i] == 'u')
	{
		++st->ptr;
		st->hold_str = conv_uint_to_str((unsigned long)va_arg(st->ap, unsigned long long), st);
		return ;
	}
	else if (*st->ptr == 'l' && st->ptr[i] == 'l' &&(st->ptr[i + 1] == 'd' || st->ptr[i + 1] == 'i'))
	{
		st->ptr += 2;
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
		return ;
	}
	else if (*st->ptr == 'l' && st->ptr[i] == 'l' && st->ptr[i + 1] == 'u')
	{
		st->ptr += 2;
		st->hold_str = conv_uint_to_str((unsigned long long)va_arg(st->ap, unsigned long long), st);
		return ;
	}
}

void	check_parser(t_var *st)
{
	size_t	i;

	i = 0;
	while (FLAGS[i])
	{
		while (FLAGS[i] && FLAGS[i] != *st->ptr)
			i++;
		flag_disp_tbl[i](st);
	}
	i = 0;
	while (i < NUM_CHECK_DISP)
		check_disp_tbl[i++](st);
	i = 0;
	while (SPECIF[i] && SPECIF[i] != *st->ptr)
		i++;
	print_disp_tbl[i](st);
}

void	parser_loop(t_var *st)
{
	while (*st->ptr)
	{
		if (*st->ptr != '%')
		{
			st->char_count += write(1, st->ptr++, 1);
			continue ;
		}
		if (*++st->ptr == '%' || *st->ptr == ' ')
		{
			while (*st->ptr == ' ' && ++st->space_count)
				st->ptr++;
			if (*st->ptr == '%')
				st->char_count += write(1, st->ptr++, 1);
			if (!ft_isalpha(*st->ptr))
				continue ;
		}
		check_parser(st);
		st->ptr++;
		st->space_count = 0;
	}
}

//error handling for only one % with nothing after.