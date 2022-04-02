/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:16:28 by mrantil           #+#    #+#             */
/*   Updated: 2022/04/02 15:53:09 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	pf_write(t_var *st)
{
	if (*st->fmt != 'u' && (*st->hold_str == '-' || st->plus_flag))
		pf_exec_before_flags(st);
	st->char_count -= ((*st->fmt == 'u') && (st->plus_flag > 0));
	if (*st->fmt == 'o' && *st->hold_str == '0' && st->precision_flag \
		&& !st->precision && !st->hash_flag && !st->astx_ret)
		return ;
	else if (*st->fmt == 'p' && *st->hold_str == '0' && st->precision_flag \
		&& !st->precision && !st->astx_ret)
		return ;
	else if (*st->fmt != 'o' && *st->hold_str == '0' \
		&& st->precision_flag && !st->precision && !st->astx_ret)
		return ;
	else if (*st->hold_str == '-' && (*st->fmt == 'd' || *st->fmt == 'i'))
		st->char_count += write(1, st->hold_str + 1, ft_strlen(st->hold_str) - 1);
	else
		st->char_count += write(1, st->hold_str, ft_strlen(st->hold_str));
}

static int	pf_intlen(unsigned long long nbr, unsigned int base)
{
	long long	count;

	count = 0;
	if (!nbr)
		return (1);
	while (nbr)
	{
		nbr /= base;
		count++;
	}
	return (count);
}

void	pf_itoa_base(unsigned long long nbr, unsigned int base, t_var *st)
{
	int	l;

	l = pf_intlen(nbr, base);
	st->hold_str = (char *)ft_strnew(l);
	if (!st->hold_str)
		exit(1);
	while (l--)
	{
		if ((*st->fmt == 'x' || *st->fmt == 'p') && nbr % base > 9)
			st->hold_str[l] = (char)(nbr % base) + 87;
		else if (*st->fmt == 'X' && nbr % base > 9)
			st->hold_str[l] = (char)(nbr % base) + 55;
		else
			st->hold_str[l] = (char)(nbr % base) + 48;
		nbr /= base;
	}
}

void	pf_exec_before_flags(t_var *st)
{
	if (*st->hold_str == '-')
	{
		if (st->plus_flag && !st->minus_flag && --st->char_count)
			st->plus_flag = 0;
		exec_precision(st);
		exec_flag_zero(st);
	}
	else if (st->plus_flag)
	{
		ft_putchar('+');
		st->for_plus = 1;
		st->plus_flag = 0;
		exec_precision(st);
		exec_flag_zero(st);
	}
}

void	exec_flags_and_length(t_var *st)
{
	st->len_va_arg = ft_strlen(st->hold_str);
	st->len_va_arg += (st->hash_flag && *st->fmt == 'o');
	st->len_va_arg += (st->hash_flag && !st->precision \
		&& st->precision_flag && *st->fmt == 'f');
	if (!st->minus_flag && st->width && !st->zero_flag)
		exec_width(st);
	if (st->va_ret >= 0)
	{
		if (!st->uint_check && ft_isalpha(*st->fmt) \
			&& st->space_count && !st->plus_flag)
			exec_flag_space(st);
		if (st->hash_flag && *st->hold_str != '0' \
			&& (*st->fmt == 'x' || *st->fmt == 'X'))
			pf_print_hex_hash(st);
		if (st->hash_flag && *st->hold_str != '0' && *st->fmt == 'o')
			st->char_count += write(1, "0", 1);
		if (st->precision_flag)
			exec_precision(st);
		if (!st->plus_flag && st->zero_flag && !st->precision_flag)
			exec_flag_zero(st);
	}
	if (*st->hold_str == '-')
		st->char_count += write(1, "-", 1);
}
