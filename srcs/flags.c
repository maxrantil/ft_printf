/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/03/07 13:28:44 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_flag(t_var *st)
{
	st->unnessesary = 1;
}

void	exec_flag_zero(t_var *st)
{
	long sub;

	sub = st->zero;
	sub -= (st->va_ret < 0);
	if (st->precision && st->zero_flag == ON)
		sub = st->precision - st->len_va_arg + st->len_va_arg;
	sub *= (sub > 0);
	while ((size_t)sub-- > st->len_va_arg)
		st->char_count += write(1, "0", 1);
	st->zero_flag = OFF;
}

void	get_flag_zero(t_var *st)
{
	if (*st->ptr == '0')
	{
		st->zero_flag = ON;
		while (*st->ptr == '0')
			st->ptr++;
		/* if (st->va_ret < 0)         			//why is this here? i dont need it, but will it make it faster?
			return ; */
		st->zero = get_it(st);
	}
}

void	hash_flag(t_var *st)
{
	if (*st->ptr == '#')
	{
		st->hash_flag = ON;
		st->ptr++;
	}
}

 void	exec_flag_space(t_var *st)
{
	if (*st->hold_str == '-') //never true now
		return ;
	if (st->space_count && !st->plus_flag)
		st->char_count += write(1, " ", 1);
}

void	flag_plus(t_var *st)
{
	if (*st->ptr == '+')
	{
		st->plus_flag = ON;
		st->ptr++;
		st->char_count++;
	}
}

void	flag_minus(t_var *st)
{
	if (*st->ptr == '-')
	{
		st->minus_flag = ON;  //here i can inplement the bitwise number
		//st->enum_flags[1] ^= 1 << 1;
		st->ptr++;
	}
}
