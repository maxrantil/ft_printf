/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/27 14:32:27 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_unsigned_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'u')
		st->hold_str = \
			uint_str((unsigned int)va_arg(st->ap, unsigned long long), st);
	else if (*st->fmt == 'h' && st->fmt[i] == 'u')
	{
		++st->fmt;
		st->hold_str = \
			uint_str((unsigned short)va_arg(st->ap, unsigned long long), st);
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'u')
	{
		++st->fmt;
		st->hold_str = \
			uint_str((unsigned long)va_arg(st->ap, unsigned long long), st);
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' && st->fmt[i + 1] == 'u')
	{
		st->fmt += 2;
		st->hold_str = \
			uint_str((unsigned char)va_arg(st->ap, unsigned long long), st);
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' && st->fmt[i + 1] == 'u')
	{
		st->fmt += 2;
		st->hold_str = uint_str(va_arg(st->ap, unsigned long long), st);
	}
	else if (*st->fmt == 'L' || (*st->fmt == 'l' && st->fmt[i] == 'f'))
	{
		++st->fmt;
		st->le_f = ON;
	}
}

void	pf_put_uint(t_var *st)
{
	if (st->plus_flag == ON)
		st->char_count--;
	if (*st->hold_str == '0' && st->precision_flag && !st->precision)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
}

int	uint_nbrlen(unsigned long long nbr)
{
	int	c;

	c = 0;
	while (nbr > 9 && ++c)
		nbr = nbr / 10;
	return (++c);
}

char	*uint_str(unsigned long long nbr, t_var *st)
{
	char	*str;
	int		l;

	st->va_u_ret = nbr;
	l = uint_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		exit(1);
	str[l] = '\0';
	while (l--)
	{
		str[l] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}

void	uint_print(t_var *st)
{
	st->uint_check = ON;
	exec_flags_and_length(st);
	pf_put_uint(st);
	st->fmt++;
}
