/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 18:43:05 by mrantil          ###   ########.fr       */
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

char	*pf_itoa_base(long int nbr, unsigned int base, const char *ptr)
{
	char	*s;
	int		l;

	l = pf_intlen(nbr, base);
	s = (char *)malloc(sizeof(char) * l + 1);
	if (!s)
		exit(1);
	s[l] = '\0';
	while (l--)
	{
		if ((*ptr == 'x' || *ptr == 'p') && nbr % base > 9)
			s[l] = (char)(nbr % base) + 87;
		else if (*ptr == 'X' && nbr % base > 9)
			s[l] = (char)(nbr % base) + 55;
		else
			s[l] = (char)(nbr % base) + 48;
		nbr /= base;
	}
	return (s);
}

void	hex_print(t_var *st)
{
	if (st->hash_flag == ON)
	{
		st->char_count += 2;
		if (*st->fmt == 'x')
			write(1, "0x", 2);
		else
			write(1, "0X", 2);
		st->hash_flag = OFF;
	}
	st->hold_str = pf_itoa_base(va_arg(st->ap, unsigned int), 16, st->fmt);
	if (!st->hold_str)
		exit(1);
	exec_flags_and_length(st);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	return ;
}
