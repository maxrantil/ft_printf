/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/17 16:40:35 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	oct_print(t_var *st)
{
	int		i;
	char 	*str;

	i = 0;
	if (st->hash_flag == ON && ++st->char_count)
	{
		write(1, "0", 1);
		st->hash_flag = OFF;
	}
	str = pf_itoa_base(va_arg(st->ap, unsigned int), 8, st->ptr);
	while (str[i] && ++st->char_count)
		ft_putchar(str[i++]);
	ft_strdel(&str);
	return ;
}
