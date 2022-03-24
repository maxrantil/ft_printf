/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add_c_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/24 19:38:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	binary_print(t_var *st)
{
	int	i;
	unsigned char octet;
	
	i = 128;
	octet = (unsigned char)va_arg(st->ap, int);
	while (octet >= 0 && i)
	{
		if ((octet / i) == 1)
			st->char_count += write(1, "1", 1);
		else
			st->char_count += write(1, "0", 1);
		if ((octet / i) == 1)
			octet -= i;
		i /= 2;
	}
	st->fmt++;
}

void	address_print(t_var *st)
{
	pf_itoa_base(va_arg(st->ap, long), 16, st);
	st->len_va_arg = ft_strlen(st->hold_str);
	if (st->width)
		st->width -= 2;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	st->char_count += write(1, "0x", 2);
	if (*st->hold_str == '0' && st->precision_zero && !st->precision)
	{
		st->fmt++;
		return ;
	}
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
	if (st->minus_flag == ON)
		exec_width(st);
	ft_strdel(&st->hold_str);
	st->fmt++;
}

static void	pf_write_str(t_var *st)
{
	size_t	len;

	len = st->len_va_arg;
	if (st->precision && st->precision < st->len_va_arg)
		st->len_va_arg = st->precision;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	if (!len && st->width)
	{
		while (len++ < st->precision)
			st->char_count += write(1, " ", 1);
	}
	else
	{
		if (!len)
			st->char_count += write(1, st->hold_str, len);
		else
			st->char_count += write(1, st->hold_str, st->len_va_arg);
	}
	if (st->minus_flag == ON)
		exec_width(st);
}

void	str_print(t_var *st)
{
	st->hold_str = va_arg(st->ap, char *);
	if (st->hold_str == NULL && st->fmt++)
	{
		st->char_count += write(1, "(null)", 6);
		return ;
	}
	st->len_va_arg = ft_strlen(st->hold_str);
	asterix_print(st);
	pf_write_str(st);
	st->fmt++;
}

void	char_print(t_var *st)
{
	st->char_width = 1;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	ft_putchar((char)va_arg(st->ap, int));
	++st->char_count;
	if (st->minus_flag == ON)
		exec_width(st);
	st->fmt++;
}