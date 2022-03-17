/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_plus_minus_hash_null.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/17 14:25:27 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_flag(t_var *st)
{
	st->unnessesary = 1;
}

void	hash_flag(t_var *st)
{
	if (*st->fmt == '#')
	{
		st->hash_flag = ON;
		st->fmt++;
	}
}

void	flag_minus(t_var *st)
{
	if (*st->fmt == '-')
	{
		st->minus_flag = ON;
		st->fmt++;
	}
}

void	flag_plus(t_var *st)
{
	if (*st->fmt == '+')
	{
		if (st->plus_flag == ON)
			st->char_count--;
		st->plus_flag = ON;
		st->fmt++;
		st->char_count++;
	}
}
