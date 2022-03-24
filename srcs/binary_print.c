/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:12:11 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/24 18:39:26 by mrantil          ###   ########.fr       */
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
