/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:01:29 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/09 17:03:05 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*pf_itoa_hex(unsigned int nbr, int base, const char *ptr)
{
	char	*s;
	int		l;

	l = pf_intlen(nbr, base);
	s = (char *)malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	while (l--)
	{
		if (*ptr == 'x' && nbr % base > 9)
			s[l] = (nbr % base) + 87;
		else if (*ptr == 'X' && nbr % base > 9)
			s[l] = (nbr % base) + 55;
		else
			s[l] = (nbr % base) + 48;
		nbr /= base;
	}
	return (s);
}

int	hex_print(t_var *st, const char *ptr, va_list ap)
{
	int		i;
	char 	*str;

	i = 0;
	if (*ptr == 'x' || *ptr == 'X')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		str = pf_itoa_hex(va_arg(ap, unsigned int), 16, ptr);
		while (str[i] && ++st->char_count)
			ft_putchar(str[i++]);
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
