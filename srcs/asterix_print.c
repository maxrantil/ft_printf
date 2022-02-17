/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterix_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:56:07 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/17 13:03:03 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	asterix_print(t_var *st)
{
	int	sub;
	
	sub = 0;
	if (*st->ptr == '*')
	{
		st->astx_ret = va_arg(st->ap, int);
		st->ptr++;
		check_parser(st);
	}
	else if (st->astx_ret)
	{
		sub = st->astx_ret;
		if (st->plus_flag == ON)
			--sub;
		while (sub-- > st->len_va_arg && ++st->char_count)
			ft_putchar(' ');
	}
	return ;
}
