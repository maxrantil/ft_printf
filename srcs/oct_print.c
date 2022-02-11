/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oct_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:33:55 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/11 14:48:34 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	oct_print(t_var *st, va_list ap)
{
	int		i;
	char 	*str;

	i = 0;
	if (*st->ptr == 'o')
	{
		if (st->space_count-- && ++st->char_count)
			ft_putchar(' ');
		str = pf_itoa_base(va_arg(ap, unsigned int), 8, st->ptr);
		while (str[i] && ++st->char_count)
			ft_putchar(str[i++]);
		ft_strdel(&str);
		return (st->char_count);
	}
	return (0);
}
