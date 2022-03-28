/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/28 21:38:05 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_signed_length(t_var *st)
{
	int	i;

	i = 1;
	if (*st->fmt == 'd' || *st->fmt == 'i')
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);
	else if (*st->fmt == 'h' && (st->fmt[i] == 'd' || st->fmt[i] == 'i'))
	{
		++st->fmt;
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
	}
	else if (*st->fmt == 'l' && (st->fmt[i] == 'd' || st->fmt[i] == 'i'))
	{
		++st->fmt;
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
	}
	else if (*st->fmt == 'h' && st->fmt[i] == 'h' \
		&& (st->fmt[i + 1] == 'd' || st->fmt[i + 1] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
	}
	else if (*st->fmt == 'l' && st->fmt[i] == 'l' \
		&& (st->fmt[i + 1] == 'd' || st->fmt[i + 1] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
	}
}

void	pf_putint(t_var *st)
{
	pf_exec_before_flags(st);
	if (st->for_plus)
		exec_flag_zero(st);
	if (*st->hold_str == '0' && st->precision_flag && !st->precision)
		return ;
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag)
		exec_width(st);
}

static size_t	pf_nbrlen(long long nbr)
{
	int	c;

	c = 0;
	if (nbr < 0 && ++c)
		nbr *= -1;
	while (nbr > 9 && ++c)
		nbr /= 10;
	return (++c);
}

char	*conv_to_str(long long nbr, t_var *st)
{
	char		*str;
	size_t		l;

	st->va_ret = nbr;
	l = pf_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * l + 1);
	if (!str)
		exit(1);
	str[l] = '\0';
	if (nbr < 0)
		nbr *= -1;
	while (l--)
	{
		str[l] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (st->va_ret < 0)
		str[0] = '-';
	if (!ft_strcmp(str, "-'..--).0-*(+,))+(0("))
		return (ft_strdup("-9223372036854775808"));
	return (str);
}

void	int_print(t_var *st)
{
	exec_flags_and_length(st);
	pf_putint(st);
	if (st->astx_ret)
		asterix_print(st);
	if (*--st->hold_str == '-')		//check this out to make cleaner
		ft_strdel(&st->hold_str);
	else
	{
		++st->hold_str;
		ft_strdel(&st->hold_str);
	}
	st->fmt++;
}
