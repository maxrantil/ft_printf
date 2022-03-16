/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/16 14:40:58 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	oct_print(t_var *st)
{
	if (st->hash_flag == ON && !st->width && *st->hold_str != '0')
	{
		st->char_count += write(1, "0", 1);
		st->hash_flag = OFF;
	}
	st->width -= (st->hash_flag && st->width);
	exec_flags_and_length(st);
	if (st->hash_flag == ON && st->width)
	{
		st->char_count += write(1, "0", 1);
		//st->width -= 1;
	}
	if (*st->hold_str == '0' && st->precision_zero && !st->precision)// && st->hash_flag)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	return ;
}
