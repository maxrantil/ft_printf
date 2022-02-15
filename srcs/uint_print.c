/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 17:38:37 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static void	pf_putuint(unsigned int nbr, t_var	*st)
{
	if (nbr > 9)
	{
		pf_putuint(nbr / 10, st);
		pf_putuint(nbr % 10, st);
	}
	else
	{
		ft_putchar((char)nbr + 48);
		st->char_count++;
	}
	return ;
}

void	uint_print(t_var *st)
{
	pf_putuint(va_arg(st->ap, unsigned int), st);
	return ;
}
