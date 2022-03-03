/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 16:59:54 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/03 19:27:44 by mrantil          ###   ########.fr       */
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

char	*conv_float_str(double nbr, int flag, t_var *st)
{
	char	*str;
	size_t	l;
	int		i;
	long	n;
	long	y;
	
	if (flag == 0)
		flag = 6;
	y = nbr;
	n = nbr;
	i = 0;
	st->va_ret = nbr;
	l = ft_intlen(n);
	str = (char *)malloc(sizeof(char) * l + flag + 1 + 1);
	if (!str)
		exit(1);
	str[l + flag + 1] = '\0';
	/* if (nbr < 0)
		nbr *= -1; */
	while (l--)
	{
		str[i++] = n % 10 + 48;
		n /= 10;
	}
	/* if (st->va_ret < 0)
		str[0] = '-'; */
	str[i++] = '.';
	while (flag--)
	{
		y = nbr * 10;
		str[i++] = y % 10 + 48;
		//nbr *= 10;
		//ft_putnbr(nbr * 10);
	}
	return (str);
}

void	float_print(t_var *st)
{
	int flag = 6; 								//this is to be changed with the char specifier flag
	
	st->hold_str = conv_float_str(va_arg(st->ap, double), flag, st);
	ft_putstr(st->hold_str);
	st->char_count += ft_strlen(st->hold_str);
	ft_strdel(&st->hold_str);
}

