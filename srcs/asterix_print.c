/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterix_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:56:07 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 22:16:47 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	asterix_print(t_var *st, va_list ap)
{
	int	len;
	int	astx_ret;
	int	int_ret;
	
	if (*st->ptr == '*')
	{
		astx_ret = va_arg(ap, int);
		int_ret = va_arg(ap, int);
		len = ft_intlen((long)int_ret);
		while (astx_ret-- > len && ++st->char_count)
			ft_putchar(' ');
		st->ptr++;
		return (st->char_count = check_parser(st, ap)); //	send it to the check_parser would be awesome, but how
														//	to combine the second va_arg all into them all?
	}
	return (0); 						// return is unnessasary on this one
}
