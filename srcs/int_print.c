/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:30:06 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/21 22:27:37 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_putint(t_var *st)
{
	if (*st->hold_str == '-')
	{
		if (st->plus_flag == ON && --st->char_count)
			st->plus_flag = OFF;
		//st->char_count += write(1, "-", 1);
		//nbr *= -1;
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

int	nbrlen(long long nbr) //write this cleaner, you can
{
	int	c;

	c = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		if (nbr == 0)
			c = 0;
		c++;
	}
	while (nbr > 9)
	{
		nbr = nbr / 10;
		c++;
	}
	return (c);
}

char	*conv_to_str(long long nbr, t_var *st) //can you use pointer instead of index? //shall you send in st to take the return directly in here insted of sending it out?
{
	char		*str;
	int			l;
	long long	n;

	n = nbr;
	st->va_ret = nbr;
	l = nbrlen(n);
	str = (char *)malloc(sizeof(char) * l + 1); //need to be freed
	if (!str)
		exit(1);
	str[l] = '\0';
	if (n < 0)
		n *= -1;
	while (l--)
	{
		str[l] = n % 10 + 48;
		n /= 10;
	}
	if (nbr < 0)
		str[0] = '-';
	return (str);
}

void	int_print(t_var *st)
{
	if (st->le_short == ON) //make this into a function in itself
		st->hold_str = conv_to_str((short)va_arg(st->ap, long long), st);
	else if (st->le_signed_char == ON)
		st->hold_str = conv_to_str((char)va_arg(st->ap, long long), st);
	else if (st->le_long == ON)
		st->hold_str = conv_to_str((long)va_arg(st->ap, long long), st);
	else if (st->le_long_long == ON)
		st->hold_str = conv_to_str(va_arg(st->ap, long long), st);
	else
		st->hold_str = conv_to_str((int)va_arg(st->ap, long long), st);


	st->len_va_arg = ft_strlen(st->hold_str); //this is the part where i should redo them into a char array?

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


/* 	else if (st->le_unsigned_char == ON)
		pf_putint((unsigned char)st->va_ret, st);

	else if (st->le_unsigned_long == ON)
		pf_putint((unsigned long)st->va_ret, st);

	else if (st->le_unsigned_long_long == ON)
		pf_putint((unsigned long long)st->va_ret, st);
	 */
		pf_putint(st);
	/* if (st->minus_flag == ON)
	{
		exec_width(st);
		//exec_flag_zero(st);
	}
	//if ((st->enum_flags[1] & MINUS) != 0) */
	return ;
}
