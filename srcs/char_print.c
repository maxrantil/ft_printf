/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:31:09 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/17 13:15:41 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	char_print(t_var *st)
{
	st->char_width = 1;
	if (st->minus_flag == OFF && st->width)
		exec_width(st);
	ft_putchar((char)va_arg(st->ap, int));
	++st->char_count;
	if (st->minus_flag == ON)
		exec_width(st);
	st->fmt++;
}
