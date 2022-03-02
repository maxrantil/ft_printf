/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/02 20:01:58 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_putint(t_var *st)
{
	if (*st->hold_str == '-')
	{
		if (st->plus_flag == ON && --st->char_count)
			st->plus_flag = OFF;
		exec_flag_space(st);
		exec_precision(st);
		exec_flag_zero(st);
		st->hold_str++;
	}
	else if (st->plus_flag == ON)
	{
		st->plus_flag = OFF;
		ft_putchar('+');
		exec_precision(st);
	}
	st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
}

static int	nbrlen(long long nbr)
{
	int	c;

	c = 0;
	if (nbr < 0 && ++c)
		nbr *= -1;
	while (nbr > 9 && ++c)
		nbr = nbr / 10;
	return (++c);
}

static char	*conv_to_str(long long nbr, t_var *st) //can you use pointer instead of index? //shall you send in st to take the return directly in here insted of sending it out?
{
	char		*str;
	size_t		l;

	st->va_ret = nbr;
	l = nbrlen(nbr);
	str = (char *)malloc(sizeof(char) * l + 1); //need to be freed
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
	return (str);
}

static void	get_signed(t_var *st)
{
	if (st->le_short == ON)
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
	else if (st->le_signed_char == ON)
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
	else if (st->le_long == ON)
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
	else if (st->le_long_long == ON)
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
	else
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);
}

void	exec_flags_and_length(t_var *st)
{
	st->len_va_arg = ft_strlen(st->hold_str);
	asterix_print(st);
	if (st->minus_flag == OFF && st->width)
	{
		exec_width(st);
	}
	if (st->va_ret >= 0)
	{
		exec_flag_space(st);
		exec_precision(st);
		exec_flag_zero(st);
	}
	if (*st->hold_str == '-') //plug_flag == ON put "+"?
		st->char_count += write(1, "-", 1);
}

void	int_print(t_var *st)
{
	get_signed(st);
	exec_flags_and_length(st);
	pf_putint(st);
	if (*--st->hold_str == '-') //this is not good practice, try fix
		ft_strdel(&st->hold_str);
	else
	{
		++st->hold_str;
		ft_strdel(&st->hold_str);
	}

}
