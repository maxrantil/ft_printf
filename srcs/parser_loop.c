/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/07 13:18:21 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_signed_length(t_var *st)
{
	int i;

	i = 1;
	if (*st->ptr == 'h' && (st->ptr[i] == 'd' || st->ptr[i] == 'i'))
	{
		st->le_short = ON;
		++st->ptr;
		return ;
	}
	else if (*st->ptr == 'h' && st->ptr[i] == 'u')
	{
		st->le_unsigned_short = ON;
		++st->ptr;
		return ;
	}
	if (*st->ptr == 'h' && st->ptr[i] == 'h' && (st->ptr[i + 1] == 'd' || st->ptr[i + 1] == 'i'))
	{
		st->le_signed_char = ON; // skip this and call directly
		++st->ptr;
		++st->ptr;
		return ;
	}
	if (*st->ptr == 'h' &&  st->ptr[i] == 'h' && st->ptr[i + 1] == 'u')
	{
		st->le_unsigned_char = ON; // skip this and call
		++st->ptr;
		++st->ptr;
		return ;
	}

}

void	check_unsigned_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->ptr == 'l' && (st->ptr[i] == 'd' || st->ptr[i] == 'i'))
	{
		st->le_long = ON;
		++st->ptr;
		return ;
	}
	if (*st->ptr == 'l' && st->ptr[i] == 'u')
	{
		st->le_unsigned_long = ON;
		++st->ptr;
		return ;
	}
	else if (*st->ptr == 'l' && st->ptr[i] == 'l' &&(st->ptr[i + 1] == 'd' || st->ptr[i + 1] == 'i'))
	{
		st->le_long_long = ON;
		++st->ptr;
		++st->ptr;
		return ;
	}
	else if (*st->ptr == 'l' && st->ptr[i] == 'l' && st->ptr[i + 1] == 'u')
	{
		st->le_unsigned_long_long = ON;
		++st->ptr;
		++st->ptr;
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