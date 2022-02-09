/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/09 17:04:20 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	flags(const char *ptr)
{
	int		i;

	i = 0;
	while (FLAGS[i] && FLAGS[i] != *ptr)
		i++;
	if (FLAGS[i] == '\0')
		return (0);
	return (1);
}

int	check_ptr(t_var *st, const char	*ptr, va_list	ap)
{
	int		i;

	i = 0;
	while (TABLE_POS[i] && TABLE_POS[i] != *ptr)
		i++;
	if (flags(ptr) && ++st->char_count)
		ft_putchar(*ptr);
	else if (TABLE_POS[i] == '\0')
		return (0);
	else
		st->char_count = disp_table[i](st, ptr, ap);
	return (st->char_count);
}