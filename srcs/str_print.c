/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:32:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 15:17:22 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	str_print(t_var *st, va_list ap)
{
	char	*str;

	if (*st->ptr == 's')
	{
		str = va_arg(ap, char *);
		while (*str && ++st->char_count)
			ft_putchar(*str++);
		return (st->char_count);
	}
	return (0);
}
