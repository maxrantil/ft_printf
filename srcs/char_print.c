/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 17:11:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	char_print(t_var *st, const char *p, va_list ap)
{
	if (*p == 'c' && ++st->char_count)
	{
		ft_putchar(va_arg(ap, int));
		return (st->char_count);
	}
	return (0);
}
