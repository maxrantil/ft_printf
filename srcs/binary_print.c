/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:12:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/08 22:44:11 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

/* void	print_bits(unsigned char octet)
{
	int	i;

	i = 128;
	while (octet >= 0 && i)
	{
		if ((octet / i) == 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		if ((octet / i) == 1)
			octet -= i;
		i /= 2;
	}
} */

void	binary_print(t_var *st)
{
	int	i;
	unsigned char octet;

	i = 256;
	octet = (unsigned char)va_arg(st->ap, int);
	while (i >>= 1)
	{
		if (octet & i)
			st->char_count += write(1, "1", 1);
		else
			st->char_count += write(1, "0", 1);
	}
}

