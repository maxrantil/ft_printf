/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterix_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:56:07 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 17:32:41 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	asterix_print(t_var *st)
{
	if (*st->ptr == '*')
	{
		st->astx_ret = va_arg(st->ap, int);
		st->ptr++;
		check_parser(st);
	}
	else
	{
		while (st->astx_ret-- > st->len_va_arg && ++st->char_count)
			ft_putchar(' ');
	}
	return ;
}
