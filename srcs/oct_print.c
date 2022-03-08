/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 19:23:35 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	oct_print(t_var *st)
{
	char 	*str;

	if (st->hash_flag == ON && ++st->char_count)
	{
		write(1, "0", 1);
		st->hash_flag = OFF;
	}
	pf_itoa_base(va_arg(st->ap, unsigned int), 8, st);
	exec_flags_and_length(st);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&str);
	return ;
}
