/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disp_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:08:16 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/08 13:15:48 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	flags(const char *p)
{
	int		i;

	i = 0;
	while (FLAGS[i] && FLAGS[i] != *p)
		i++;
	if (FLAGS[i] == '\0')
		return (0);
	return (1);
}

int	check_ptr(t_var *st, const char	*p, va_list	ap)
{
	int		i;

	i = 0;
	while (TABLE_POS[i] && TABLE_POS[i] != *p)
		i++;
	if (flags(p) && ++st->char_count)
		ft_putchar(*p);
	else if (TABLE_POS[i] == '\0')
		return (0);
	else
		st->char_count = disp_table[i](st, p, ap);
	return (st->char_count);
}