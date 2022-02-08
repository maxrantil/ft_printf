/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 22:27:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_putuint(unsigned int nbr, t_var *st)
{
	if (nbr > 9)
	{
		pf_putuint(nbr / 10, st);
		pf_putuint(nbr % 10, st);
	}
	else
	{
		ft_putchar(nbr + 48);
		st->char_count++;
	}
	return (st->char_count);
}

int	uint_print(t_var *st, const char *p, va_list ap)
{
	if (*p == 'u')
	{
		st->char_count = pf_putuint(va_arg(ap, unsigned int), st);
		return (st->char_count);
	}
	return (0);
}
