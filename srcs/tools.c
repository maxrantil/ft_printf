/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 18:16:28 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/24 19:22:42 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

static int	pf_intlen(long long nbr, unsigned int base)
{
	int	count;

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

void	exec_flags_and_length(t_var *st)
{
	st->len_va_arg = ft_strlen(st->hold_str);
	asterix_print(st);
	if (st->minus_flag == OFF && st->width && !st->zero_flag)
		exec_width(st);
	if (st->va_ret >= 0)
	{
		if (!st->uint_check)
			exec_flag_space(st);
		if (st->zero_flag)
			exec_precision(st);
		if (st->hash_flag == ON && *st->hold_str != '0' && !st->width && (*st->fmt == 'x' || *st->fmt == 'X'))
			pf_print_hex_hash(st);
		if (st->hash_flag == ON && *st->hold_str != '0' && !st->width && *st->fmt == 'o')
			st->char_count += write(1, "0", 1);
		if (!st->zero_flag)
			exec_precision(st);
		if (!st->plus_flag)
			exec_flag_zero(st);
	}
	if (*st->hold_str == '-')
		st->char_count += write(1, "-", 1);
}