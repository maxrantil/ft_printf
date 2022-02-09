/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/09 18:49:53 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	check_ptr(t_var *st, const char	*ptr, va_list ap)
{
	int		i;

	i = 0;
	while (CHAR_CONV[i] && CHAR_CONV[i] != *ptr)
		i++;
	if (flags(st, ptr, ap))
		return (++st->char_count);
	else if (CHAR_CONV[i] == '\0')
		return (0);
	return (st->char_count = print_disp_tbl[i](st, ptr, ap));
}