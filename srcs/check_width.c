/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:16:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:53:58 by mrantil          ###   ########.fr       */
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

int	check_width(t_var *st)
{
	int c;

	c = 0;
	if (ft_isdigit(*st->ptr))
	{	
		while (ft_isdigit(*st->ptr) && ++c)
		{
			if (c == 1)
			{
				st->width = *st->ptr - 48;
				c++;
			}	
			else	
				st->width *= 10 + (*st->ptr - 48);
			st->ptr++;
		}
		return (check_parser(st));
	}
	if (st->len_va_arg)
	{
		while (st->width-- > st->len_va_arg && ++st->char_count) // check later for width > st->len_va_arg, or simular
			ft_putchar(' ');
	}
	return (0);
}


/* 		while (ft_isdigit(*st->ptr))
		{ */
/* 			st->width += save_width(*st->ptr);
			st->ptr++; */
/* 		} */