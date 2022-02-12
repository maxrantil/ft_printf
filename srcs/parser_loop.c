/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 20:22:58 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	flags(t_var *st, va_list ap)
{
	int		i;

	i = 0;
	if (*st->ptr == '%')
		return (st->char_count = procentage_print(st));
	while (FLAGS[i] && FLAGS[i] != *st->ptr)
		++i;
	if (FLAGS[i] == '\0' || !st->char_count)
		return (0);
	else
		return (st->char_count = flag_disp_tbl[i](st, ap));
}

static int	check_parser(t_var *st, va_list ap)
{
/* 	t_enum_conversions	e_conv; */
	int					i;

	i = 0;
	while (CHAR_CONV[i] && CHAR_CONV[i] != *st->ptr)
		i++;
	if (flags(st, ap))
		return (++st->char_count);
	else if (CHAR_CONV[i] == '\0')
		return (0);
/* 	e_conv = i; */
	return (st->char_count = print_disp_tbl[i](st, ap));
}

int	parser_loop(t_var st, va_list ap)
{
	while (*st.ptr)
	{
		if (*st.ptr != '%' && ++st.char_count)
		{
			ft_putchar(*st.ptr++);
			continue ;
		}
		st.ptr++;
		while (*st.ptr == ' ' && ++st.space_count && ++st.char_count)
			st.ptr++;
		if (st.space_count > 1)
			st.char_count -= st.space_count;
		st.char_count = check_parser(&st, ap);
		if (!st.char_count)
			return (-1);
		st.ptr++;
		st.space_count = 0;
	}
	return (st.char_count);
}
