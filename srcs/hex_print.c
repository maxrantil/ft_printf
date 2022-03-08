/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 20:30:22 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_intlen(long nbr, unsigned int base)
{
	int	count;

	count = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

void	pf_itoa_base(long long nbr, unsigned int base, t_var *st)
{
	int		l;

	l = pf_intlen(nbr, base);
	st->hold_str = (char *)ft_strnew(sizeof(char) * l);
	if (!st->hold_str)
		exit(1);
	while (l--)
	{
		if ((*st->fmt == 'x' || *st->fmt == 'p') && nbr % base > 9)
			st->hold_str[l] = (char)(nbr % base) + 87;
		else if (*st->fmt == 'X' && nbr % base > 9)
			st->hold_str[l] = (char)(nbr % base) + 55;
		else
			st->hold_str[l] = (char)(nbr % base) + 48;
		nbr /= base;
	}
}

void	hex_print(t_var *st)
{
	if (st->hash_flag == ON && *st->hold_str != '0')
	{
		st->char_count += 2;
		if (*st->fmt == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		st->hash_flag = OFF;
	}
	exec_flags_and_length(st);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	return ;
}
