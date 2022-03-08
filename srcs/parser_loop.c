/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 18:09:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

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