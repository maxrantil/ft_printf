/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:54 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/17 14:38:28 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	conv_float_str(long double nbr, int flag, t_var *st)
{
	size_t		l;
	int			i;
	long long	n;
	char		y;

	y = 0;
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
	st->hold_str = (char *)ft_strnew(l + flag + 1);
	if (!st->hold_str)
		exit(1);
	while (l--)
	{
		st->hold_str[i++] = n % 10 + 48;					//use write to write out the number before one by one. (probably before this function.)
		n /= 10;
	}
	if (flag)
		st->hold_str[i++] = '.';
	n = nbr;
	while (flag--)
	{
		n = nbr * 10;
		st->hold_str[i++] = n % 10 + 48;
		nbr *= 10;
	}
	n = nbr * 10;
	y = n % 10 + 48;
	if (y >= 5 && y > st->hold_str[--i] && st->precision < 17)			///17 is hardcoded because that the maximum i can print correct ATM
	{
		if (st->hold_str[0] % 2 == 0 && st->hold_str[i - 1] != 0)	//changed here to i - 1 instead of --i, All this i fucked, clean it!
			--st->hold_str[i];
		else
		{
			if (st->hold_str[i] == '9')
			{
				while (st->hold_str[i] == '9')
				{
					st->hold_str[i--] = '0';
					++st->hold_str[i];
				}
			}
			else
				++st->hold_str[i];
		}
	}
}

void	float_print(t_var *st)
{
	int flag = 6;

	if (st->prec_noll)
		flag = st->precision;
	if (st->le_F == ON)
		conv_float_str(va_arg(st->ap, long double), flag, st);
	else
		conv_float_str(va_arg(st->ap, double), flag, st);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	ft_strdel(&st->hold_str);
	st->fmt++;
}

