/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:33:03 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/02 20:02:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_put_uint(t_var *st)
{
	if (st->plus_flag == ON)
	{
		st->plus_flag = OFF;
		ft_putchar('+');
		exec_precision(st);
	}
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

static char	*conv_uint_to_str(unsigned long long nbr, t_var *st)
{
	char	*str; //can you use pointer instead of index? shall you send in st to take the return directly in here insted of sending it out?
	int		l;

	st->va_u_ret = nbr; //change a to va_u_ret that is involved in unit
	l = uint_nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * l + 1);
		exit(1);
	str[l] = '\0';
	while (l--)
	{
		str[l] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (str);
}


static void	get_uint(t_var *st)
{
	if (st->le_unsigned_short == ON)
		st->hold_str = conv_uint_to_str((unsigned short)va_arg(st->ap, unsigned long long), st);
	else if (st->le_unsigned_char == ON)
		st->hold_str = conv_uint_to_str((unsigned char)va_arg(st->ap, unsigned long long), st);
	else if (st->le_unsigned_long == ON)
		st->hold_str = conv_uint_to_str((unsigned long)va_arg(st->ap, unsigned long long), st);
	else if (st->le_unsigned_long_long == ON)
		st->hold_str = conv_uint_to_str((unsigned long long)va_arg(st->ap, unsigned long long), st);
	else
		st->hold_str = conv_uint_to_str((unsigned int)va_arg(st->ap, unsigned long long), st);
}

void	uint_print(t_var *st)
{
	get_uint(st);
	exec_flags_and_length(st);
	pf_put_uint(st);
}
