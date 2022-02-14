/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterix_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:56:07 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 11:48:08 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	asterix_print(t_var *st, va_list ap)
{
	if (*st->ptr == '*')
	{
		st->astx_ret = va_arg(ap, int);
		st->ptr++;
		return (st->char_count = check_parser(st, ap));
	}
	else
		while (st->astx_ret-- > st->len_va_arg && ++st->char_count)
			ft_putchar(' ');
	return (0); 						// return is unnessasary on this one
}
