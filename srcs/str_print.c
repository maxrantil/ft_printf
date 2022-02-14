/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/14 15:54:35 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	str_print(t_var *st)
{
	char	*str;

	if (*st->ptr == 's' || asterix_print(st))
	{
		str = va_arg(st->ap, char *);
		st->len_va_arg = ft_strlen(str);
		asterix_print(st);
		while (*str && ++st->char_count)
			ft_putchar(*str++);
		return (st->char_count);
	}
	return (0);
}
