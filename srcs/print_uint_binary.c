/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uint_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/29 22:17:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	check_unsigned_length(t_var *st)
{
	if (*st->fmt == 'u')
		st->hold_str = \
			uint_str((unsigned int)va_arg(st->ap, unsigned long long), st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'u' && ++st->fmt)
		st->hold_str = \
			uint_str((unsigned short)va_arg(st->ap, unsigned long long), st);
	else if (*st->fmt == 'l' && st->fmt[1] == 'u' && ++st->fmt)
		st->hold_str = \
			uint_str((unsigned long)va_arg(st->ap, unsigned long long), st);
	else if (*st->fmt == 'h' && st->fmt[1] == 'h' && st->fmt[2] == 'u')
	{
		st->fmt += 2;
		st->hold_str = \
			uint_str((unsigned char)va_arg(st->ap, unsigned long long), st);
	}
	else if (*st->fmt == 'l' && st->fmt[1] == 'l' && st->fmt[2] == 'u')
	{
		st->fmt += 2;
		st->hold_str = uint_str(va_arg(st->ap, unsigned long long), st);
	}
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
	st->uint_check = 1;
	exec_flags_and_length(st);
	pf_write(st);
	if (st->minus_flag)
		exec_width(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}

void	binary_print(t_var *st)
{
	pf_itoa_base(va_arg(st->ap, long long), 2, st);
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	st->fmt++;
}
