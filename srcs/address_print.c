/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:31:57 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/16 14:58:07 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	address_print(t_var *st)				//only minus and width flags for pointers
{
	pf_itoa_base(va_arg(st->ap, long), 16, st);
	st->len_va_arg = ft_strlen(st->hold_str);
	if (st->width)
		st->width -= 2;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	st->char_count += write(1, "0x", 2);
	if (*st->hold_str == '0' && st->precision_zero && !st->precision)// && st->hash_flag)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	return ;
}
