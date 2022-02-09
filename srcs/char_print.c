/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/09 17:02:24 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	char_print(t_var *st, const char *ptr, va_list ap)
{
	if (*ptr == 'c' && ++st->char_count)
	{
		ft_putchar(va_arg(ap, int));
		return (st->char_count);
	}
	return (0);
}
