/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 16:30:15 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_intlen_oct(long nbr, int base)
{
	int	count;

	count = 1;
	if (nbr <= 0)
	{
		nbr *= -1;
		if (nbr == 0)
			count = 0;
		count++;
	}
	while (nbr >= base) // >base or >= base? 
	{
		nbr /= base;
		count++;
	}
	return (count);
}

static char	*pf_itoa_oct(int nbr, int base)
{
	char	*s;
	int		l;
	long	n;

	n = nbr;
	l = pf_intlen_oct(n, base);
	s = (char *)malloc(sizeof(char) * l + 1);
	if (!s)
		return (NULL);
	s[l] = '\0';
	if (n < 0)
		n *= -1;
	while (l--)
	{
		s[l] = (n % base) + 48;
		n /= base;
	}
	if (nbr < 0)
		s[0] = '-';
	return (s);
}

int	oct_print(t_var *st, const char *p, va_list ap)
{
	int		ret;
	int		i;
	char 	*str;

	ret = va_arg(ap, int);
	i = 0;
	if (*p == 'o')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		if (ret)
		{
			str = pf_itoa_oct(ret, 8);
			while (str[i] && ++st->char_count)
				ft_putchar(str[i++]);
		}
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
