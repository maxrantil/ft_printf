/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 21:01:52 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_intlen_hex(unsigned int nbr, int base)
{
	int	count;

	count = 0;
	while (nbr)
	{
		nbr = nbr / base;
		count++;
	}
	return (count);
}

static char	*pf_itoa_hex(unsigned int nbr, int base, const char *p) // 87 for small 55 for big 48
{
	char	*s;
	int		l;

	l = pf_intlen_hex(nbr, base);
	s = (char *)malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	while (l--)
	{
		if (*p == 'x' && nbr % base > 9)
			s[l] = (nbr % base) + 87;
		else if (*p == 'X' && nbr % base > 9)
			s[l] = (nbr % base) + 55;
		else
			s[l] = (nbr % base) + 48;
		nbr /= base;
	}
	return (s);
}

int	hex_print(t_var *st, const char *p, va_list ap)
{
	int		i;
	char 	*str;

	i = 0;
	if (*p == 'x' || *p == 'X')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		str = pf_itoa_hex(va_arg(ap, unsigned int), 16, p);
		while (str[i] && ++st->char_count)
			ft_putchar(str[i++]);
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
