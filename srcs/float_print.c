/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:54 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/02 20:47:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	floatlen(double nbr)
{
	int	c;
	//int	*ptr;

	//ptr = nbr;
	c = 0;
	if (nbr < 0 && ++c)
		nbr *= -1;
	while (nbr != 9)
	{
		//if (*ptr == '.')
		nbr = nbr / 10;
		++c;
	}
	return (++c);
}

char	*conv_float_str(double nbr, t_var *st)
{
	char		*str;
	size_t		l;

	st->va_ret = nbr;
	l = floatlen(nbr);
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		exit(1);
	str[l] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (l--)
	{
		str[l] = nbr / (l - 1) + 48;
		nbr /= 10;
	}
	if (st->va_ret < 0)
		str[0] = '-';
	return (str);
}

void	float_print(t_var *st)
{
	//pf_putfloat(va_arg(st->ap, double));
	st->hold_str = conv_float_str(va_arg(st->ap, double), st);
	ft_putstr(st->hold_str);
}

