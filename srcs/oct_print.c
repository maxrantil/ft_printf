/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 20:06:37 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_intlen_oct(unsigned int nbr, unsigned int base)
{
	int	count;

	count = 0;
	if (!nbr)
		return (1);
	while (nbr) // >base or >= base?
	{
		nbr /= base;
		count++;
	}
	return (count);
}

static char	*pf_itoa_oct(unsigned int nbr, unsigned int base)
{
	char	*s;
	int		l;

	l = pf_intlen_oct(nbr, base);
	s = (char *)malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	while (l--)
	{
		s[l] = (nbr % base) + 48;
		nbr /= base;
	}
	return (s);
}

int	oct_print(t_var *st, const char *p, va_list ap)
{
	int		i;
	char 	*str;

	i = 0;
	if (*p == 'o')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		str = pf_itoa_oct(va_arg(ap, unsigned int), 8);
		while (str[i] && ++st->char_count)
			ft_putchar(str[i++]);
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
