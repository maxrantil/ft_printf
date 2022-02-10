/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 15:18:47 by mrantil          ###   ########.fr       */
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
		i++;
	if (FLAGS[i] == '\0' || !st->char_count)
		return (0);
	else
		return (st->char_count = flag_disp_tbl[i](st, ap));
}

int	check_ptr(t_var *st, va_list ap)
{
	int		i;

	i = 0;
	while (CHAR_CONV[i] && CHAR_CONV[i] != *st->ptr)
		i++;
	if (flags(st, ap))
		return (++st->char_count);
	else if (CHAR_CONV[i] == '\0')
		return (0);
	return (st->char_count = print_disp_tbl[i](st, ap));
}