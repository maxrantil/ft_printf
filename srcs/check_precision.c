/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:09:00 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 17:12:16 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* int	save_width(int nbr)
{
	if (nbr > 9)
	{
		save_width(nbr / 10);
		save_width(nbr % 10);
	}
	return (nbr);
} */

int	check_precision(t_var *st)
{
	int c;

	c = 0;
	if (*st->ptr == '.')
	{
		st->ptr++;
		while (ft_isdigit(*st->ptr) && ++c)
		{
			if (c == 1)
			{
				st->precision = *st->ptr - 48;
				c++;
			}	
			else	
				st->precision = st->width * 10 + (*st->ptr - 48);
			st->ptr++;
		}
		return (check_parser(st));
	}
	if (st->len_va_arg)
	{
		while (st->precision-- > st->len_va_arg && ++st->char_count) // check later for width > st->len_va_arg, or simular
			ft_putchar('0');
	}
	return (0);
}