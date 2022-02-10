/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/10 15:14:30 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int plus_flag(t_var *st, va_list ap)
{
	if (*st->ptr == '+')
	{
		st->flag = ON;
		return (int_print(st, ap));
	}
	return (0);
}

int	procentage_print(t_var *st)
{
	ft_putchar(*st->ptr);
	return (st->char_count);
}
