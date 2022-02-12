/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/12 20:55:55 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int flag_plus(t_var *st, va_list ap)
{
	if (*st->ptr == '+')
	{
		st->flag = ON;
		st->ptr++;
		return (int_print(st, ap));
	}
	return (0);
}

int	procentage_print(t_var *st)
{
	ft_putchar(*st->ptr);
	return (st->char_count);
}
