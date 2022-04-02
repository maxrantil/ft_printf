/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/02 15:03:33 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_signed_length(t_var *st)
{
	if (*st->fmt == 'd' || *st->fmt == 'i')
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);
	else if (*st->fmt == 'h' && (st->fmt[1] == 'd' || st->fmt[1] == 'i') \
		&& ++st->fmt)
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
	else if (*st->fmt == 'l' && (st->fmt[1] == 'd' || st->fmt[1] == 'i') \
		&& ++st->fmt)
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'h' \
		&& (st->fmt[2] == 'd' || st->fmt[2] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
	}
	else if (*st->fmt == 'l' && st->fmt[1] == 'l' \
		&& (st->fmt[2] == 'd' || st->fmt[2] == 'i'))
	{
		st->fmt += 2;
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
	}
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
	if (st->zero_flag && st->precision_flag)
		ignore_zero_flag(st);
	exec_flags_and_length(st);
	pf_write(st);
	if (st->minus_flag)
		exec_width(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}

void	address_print(t_var *st)
{
	pf_itoa_base(va_arg(st->ap, long), 16, st);
	st->len_va_arg = ft_strlen(st->hold_str);
	if (st->width)
		st->width -= 2;
	if (!st->minus_flag && st->width)
		exec_width(st);
	st->char_count += write(1, "0x", 2);
	pf_write(st);
	if (st->minus_flag)
		exec_width(st);
	if (st->astx_ret)
		asterix_print(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}
