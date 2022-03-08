/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:54 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 12:37:05 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* static int	floatlen(double nbr)
{
	int	c;
	//int	*ptr;

	//ptr = nbr;
	c = 0;
	if (nbr < 0 && ++c)
		nbr *= -1;
	while (nbr > 9)
	{
		//if (*ptr == '.')
		nbr = nbr / 10;
		++c;
	}
	return (++c);
} */

/* static int	floatlen(double nbr)
{
	int	c;
	//int	*ptr;

	//ptr = nbr;
	c = 0;
	if (nbr < 0 && ++c)
		nbr *= -1;
	while (nbr > 9)
	{
		//if (*ptr == '.')
		nbr = nbr / 10;
		++c;
	}
	return (++c);
} */

char	*conv_float_str(long double nbr, int flag, t_var *st)
{
	char	*str;
	size_t	l;
	int		i;
	long long	n;
	char		y;

	y = 0;
	if (!flag)
		flag = 6;
	if (nbr < 0)
	{
		nbr *= -1;
		st->char_count += write(1, "-", 1);
	}
	if (1 / nbr < 0)
		st->char_count += write(1, "-", 1);
	n = nbr;
	i = 0;
	st->va_ret = nbr;
	l = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * l + flag + 1 + 1);
	if (!str)
		exit(1);
	str[l + flag + 1] = '\0';
	while (l--)
	{
		str[i++] = n % 10 + 48;					//use write to write out the number before one by one. (probably before this function.)
		n /= 10;
	}
	str[i++] = '.';
	n = nbr;
	while (flag--)
	{
		n = nbr * 10;
		str[i++] = n % 10 + 48;
		nbr *= 10;
	}
	n = nbr * 10;
	y = n % 10 + 48;
	if (str[--i] < y && st->precision < 17)			///17 is hardcoded because that the maximum i can print correct ATM
	{
		++str[i];
/* 		while (str[i] == '9')
		{
			str[i--] = '0';
			++str[i];
		} */
	}
	return (str);
}

void	float_print(t_var *st)
{
	int flag = 6;

	if (st->precision)
		flag = st->precision;
	if (st->le_F == ON)
		st->hold_str = conv_float_str(va_arg(st->ap, long double), flag, st);
	else
		st->hold_str = conv_float_str(va_arg(st->ap, double), flag, st);
	ft_putstr(st->hold_str);
	st->char_count += ft_strlen(st->hold_str);
	ft_strdel(&st->hold_str);
}

