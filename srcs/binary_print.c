/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:12:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:53:12 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static char	*pf_itoa_binary(unsigned int nbr, unsigned int base)
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
		s[l] = (nbr % base) + 48;
		nbr /= base;
	}
	return (s);
}

int	binary_print(t_var *st)
{
	int		i;
	char 	*str;

	i = 0;
	if (*st->ptr == 'b')
	{
		str = pf_itoa_binary(va_arg(st->ap, unsigned int), 2);
		while (str[i] && ++st->char_count)
			ft_putchar(str[i++]);
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
