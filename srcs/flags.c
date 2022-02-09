/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/09 18:42:38 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int plus_flag(t_var *st, const char	*ptr, va_list ap)
{
	if (*ptr++ == '+')
		int_print(st, ptr, ap);
	return (0); ///this is ot nessasary atm
}

int	symbol_print(t_var *st, const char	*ptr)
{
	ft_putchar(*ptr);
	return (++st->char_count);
}

int	flags(t_var *st, const char *ptr, va_list ap)
{
	int		i;

	i = 0;
	if (*ptr == '%' || *ptr == '\n')
		st->char_count = symbol_print(st, ptr);
	while (FLAGS[i] && FLAGS[i] != *ptr)
		i++;
	if (FLAGS[i] == '\0' || !st->char_count)
		return (0);
	else
		st->char_count = flag_disp_tbl[i](st, ptr, ap);
	return (1);
}