/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/11 14:57:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_intlen(unsigned int nbr, unsigned int base)
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

char	*pf_itoa_base(unsigned int nbr, unsigned int base, const char *ptr)
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
		if (*ptr == 'x' && nbr % base > 9)
			s[l] = (char)(nbr % base) + 87;
		else if (*ptr == 'X' && nbr % base > 9)
			s[l] = (char)(nbr % base) + 55;
		else
			s[l] = (char)(nbr % base) + 48;
		nbr /= base;
	}
	return (s);
}

int	hex_print(t_var *st, va_list ap)
{
	int		i;
	char 	*str;

	i = 0;
	if (*st->ptr == 'x' || *st->ptr == 'X')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		str = pf_itoa_base(va_arg(ap, unsigned int), 16, st->ptr);
		while (str[i] && ++st->char_count)
			ft_putchar(str[i++]);
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
