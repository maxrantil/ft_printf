/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 16:40:36 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_putuint(unsigned int nbr, int char_count)
{
	if (nbr > 9)
	{
		pf_putuint(nbr / 10, char_count);
		pf_putuint(nbr % 10, char_count);
	}
	else
	{
		ft_putchar(nbr + 48);
		char_count++;
	}
	return (char_count);
}

int	uint_print(t_var *st, va_list ap)
{
	if (*st->ptr == 'u')
	{
		st->char_count = pf_putuint(va_arg(ap, unsigned int), st->char_count);
		return (st->char_count);
	}
	return (0);
}
