/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/15 14:45:10 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int flag_plus(t_var *st)
{
	if (*st->ptr == '+')
	{
		st->plus_flag = ON;
		st->ptr++;
		st->char_count++;
		return (check_parser(st));
	}
	return (0);
}

int flag_minus(t_var *st)
{
	if (*st->ptr == '-')
	{
		st->minus_flag = ON;
		st->ptr++;
		return (check_parser(st)); // can this to go checkk_width directly?
	}
	return (0);
}

int	procentage_print(t_var *st)
{
	ft_putchar(*st->ptr);
	return (st->char_count);
}
