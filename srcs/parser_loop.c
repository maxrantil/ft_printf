/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/20 17:33:02 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_length(t_var *st)
{
	if (*st->ptr == 'h' && (*++st->ptr == 'd' || *st->ptr == 'i'))
		st->le_short = ON;
	else if (*st->ptr == 'h' && *++st->ptr == 'u')
		st->le_unsigned_short = ON;
	else if (*st->ptr == 'h' && *++st->ptr == 'h' && (*++st->ptr == 'd' || *st->ptr == 'i'))
	{
		st->le_signed_char = ON;
		++st->ptr;
	}
/* 	else if (*st->ptr == 'h' && *++st->ptr == 'h' && *++st->ptr == 'u')
	{
		st->le_unsigned_char = ON;
		++st->ptr;
	}
	else if (*st->ptr == 'l' && (*++st->ptr == 'd' || *st->ptr == 'i'))
		st->le_long = ON;
	else if (*st->ptr == 'l' && *++st->ptr == 'u')
		st->le_unsigned_long = ON;
	else if (*st->ptr == 'l' && *++st->ptr == 'l' && (*++st->ptr == 'd' || *st->ptr == 'i'))
	{
		st->le_long_long = ON;
		++st->ptr;
	}
	else if (*st->ptr == 'l' && *++st->ptr == 'l' && *++st->ptr == 'u')
	{
		st->le_unsigned_long_long = ON;
		++st->ptr;
	} */
}

void	check_parser(t_var *st)
{
	size_t	i;
	
	i = 0;
	while (FLAGS[i] && FLAGS[i] != *st->ptr)
		i++;
	flag_disp_tbl[i](st);
	i = 0;
	while (i < NUM_CHECK_DISP)
		check_disp_tbl[i++](st);
	i = 0;
	while (SPECIF[i] && SPECIF[i] != *st->ptr)
		i++;
	print_disp_tbl[i](st);
	return ;
}

void	parser_loop(t_var *st)
{
	while (*st->ptr)
	{
		if (*st->ptr != '%' && ++st->char_count)
		{
			ft_putchar(*st->ptr++);
			continue ;
		}
		st->ptr++;
		check_parser(st);
		st->ptr++;
		st->space_count = 0;
	}
}


//error handling for only one % with nothing after.