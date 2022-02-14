/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterix_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:56:07 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:59:02 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	asterix_print(t_var *st)
{
	if (*st->ptr == '*')
	{
		st->astx_ret = va_arg(st->ap, int);
		st->ptr++;
		return (check_parser(st));
	}
	else
	{
		while (st->astx_ret-- > st->len_va_arg && ++st->char_count)
			ft_putchar(' ');
	}
	return (0);
}
