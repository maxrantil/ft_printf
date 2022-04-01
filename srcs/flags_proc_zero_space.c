/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_proc_zero_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/01 13:38:40 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	exec_flag_space(t_var *st)
{
	if (ft_isalpha(*st->fmt) && st->space_count && !st->plus_flag)
		st->char_count += write(1, " ", 1);
}

void	get_flag_space(t_var *st)
{
	while (*st->fmt == ' ' && ++st->space_count)
		st->fmt++;
}

void	exec_flag_zero(t_var *st)
{
	long	sub;

	sub = st->zero;
	sub += (st->width > 0 && st->zero_flag > 0) * st->width;
	if (*st->fmt == 'x' || *st->fmt == 'X')
		sub -= (st->hash_flag > 0) * 2;
	sub -= (st->for_plus > 0 || st->space_count > 0);
	sub *= (sub > 0);
	while ((size_t)sub-- > st->len_va_arg)
		st->char_count += write(1, "0", 1);
}

void	get_flag_zero(t_var *st)
{
	if (*st->fmt == '0')
	{
		while (*st->fmt == '0')
			st->fmt++;
		if (!st->minus_flag)
		{
			st->zero_flag = 1;
			st->zero = get_it(st);
		}
	}
}
