/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/07 16:35:03 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_putint(int n, t_var *st)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
	{
		pf_putint(nbr / 10, st);
		pf_putint(nbr % 10, st);
	}
	else
	{
		ft_putchar(nbr + 48);
		st->char_count++;
	}
	return (st->char_count);
}

int	int_print(t_var *st, const char *p, va_list ap)
{
	int		ret;

	ret = va_arg(ap, int);
	if (*p == 'd' || *p == 'i')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		if (ret)
			st->char_count = pf_putint(ret, st);
		return (st->char_count);
	}
	return (st->char_count);
}

