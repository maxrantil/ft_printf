/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/11 14:32:08 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	char_print(t_var *st, va_list ap)
{
	if (*st->ptr == 'c' && ++st->char_count)
	{
		ft_putchar((char)va_arg(ap, int));
		return (st->char_count);
	}
	return (0);
}
