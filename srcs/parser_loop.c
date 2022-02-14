/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 17:08:43 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	check_flags(t_var *st)
{
	int	i;

	i = 0;
	if (*st->ptr == '%')
		return (st->char_count = procentage_print(st));
	while (FLAGS[i] && FLAGS[i] != *st->ptr)
		++i;
	if (FLAGS[i] == '\0' || !st->char_count)
		return (0);
	else
		return (st->char_count = flag_disp_tbl[i](st));
}

int	check_parser(t_var *st)
{
	int	i;

	i = 0;
	while (SPECIF[i] && SPECIF[i] != *st->ptr)
		i++;
	if (check_flags(st))
		return (++st->char_count); //this might be more then one later?
	if (check_width(st))
		return (st->char_count);
	if (check_precision(st))
		return (st->char_count);
	else if (SPECIF[i] == '\0')
		return (0);
	return (st->char_count = print_disp_tbl[i](st));
}

int	parser_loop(t_var st)
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
		st.char_count = check_parser(&st);
		if (!st.char_count)
			return (-1);
		st.ptr++;
		st.space_count = 0;
	}
	return (st.char_count);
}
