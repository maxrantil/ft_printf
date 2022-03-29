/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_plus_minus_hash_null.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/29 21:53:28 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

size_t	get_it(t_var *st)
{
	size_t	c_single;
	size_t	ret;

	c_single = 0;
	ret = 0;
	st->width_check = 1;
	while (ft_isdigit(*st->fmt) && ++c_single)
	{
		if (c_single == 1 && ++c_single)
			ret = *st->fmt - 48;
		else
			ret = ret * 10 + (*st->fmt - 48);
		st->fmt++;
	}
	return (ret);
}

void	null_flag(t_var *st)
{
	st->sign = 0;
}

void	hash_flag(t_var *st)
{
	if (*st->fmt == '#')
	{
		st->hash_flag = 1;
		st->fmt++;
	}
}

void	flag_minus(t_var *st)
{
	if (*st->fmt == '-')
	{
		if (st->zero_flag)
			st->zero_flag = 0;
		st->minus_flag = 1;
		st->fmt++;
	}
}

void	flag_plus(t_var *st)
{
	if (*st->fmt == '+')
	{
		if (st->plus_flag)
			st->char_count--;
		st->plus_flag = 1;
		st->fmt++;
		st->char_count++;
	}
}
