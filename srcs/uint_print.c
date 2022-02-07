/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/07 16:35:20 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_putuint(int n, t_var *st)
{
	unsigned int	nbr;

	nbr = (unsigned int)n;
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
	int		ret;

	ret = va_arg(ap, int);
	if (*p == 'u')
	{
		if (ret)
			st->char_count = pf_putuint(ret, st);
		return (st->char_count);
	}
	return (st->char_count);
}
