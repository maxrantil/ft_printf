/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/16 13:43:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_parser(t_var *st)
{
	int	i;

	i = 0;
	while (FLAGS[i] && FLAGS[i] != *st->ptr)
		++i;
	flag_disp_tbl[i](st);
	if (ft_isdigit(*st->ptr) || *st->ptr == '.')				///do sommething cleaner here??
	{
		check_width(st);
		check_precision(st);
	}
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
		if (!st->char_count)
			exit(1);
		st->ptr++;
		st->space_count = 0;
	}
}
