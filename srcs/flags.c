/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrantil <mrantil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:05:47 by mrantil           #+#    #+#             */
/*   Updated: 2022/02/19 19:17:48 by mrantil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	null_flag(t_var *st)
{
	st->unnessesary = 1;
	return ;
}

void	exec_flag_zero(t_var *st)
{
	int sub;

	sub = st->zero;
	sub -= (st->int_ret < 0);
	if (st->precision && st->zero_flag == ON)
		sub = st->precision - st->len_va_arg + st->len_va_arg;
	sub *= (sub > 0);
	while (sub-- > st->len_va_arg)
		st->char_count += write(1, "0", 1);
	st->zero_flag = OFF;
}

void	get_flag_zero(t_var *st)
{
	int c_single;
	
	c_single = 0;
	st->zero_flag = ON;
	while (*st->ptr == '0')
		st->ptr++;
	/* if (st->int_ret < 0)         			//why is this here? i dont need it, but will it make it faster?
		return ; */
	while (ft_isdigit(*st->ptr) && ++c_single)
	{
		if (c_single == 1 && ++c_single)
			st->zero = *st->ptr - 48;
		else	
			st->zero = st->zero * 10 + (*st->ptr - 48);
		st->ptr++;
	}
}

void	hash_flag(t_var *st)
{
	st->hash_flag = ON;
	st->ptr++;
}

void	get_flag_space(t_var *st)
{
	while (*st->ptr == ' ' && ++st->space_count) // && ++st->char_count) //cleaning up
			st->ptr++;
	/* if (st->space_count > 1)					//is this nessesary?
		st->char_count -= st->space_count; */
}

void	exec_flag_space(t_var *st)
{
	if (st->int_ret < 0)
		return ;
	if (st->space_count-- && ++st->char_count)
		ft_putchar(' ');
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
	return ;
}

void	procentage_print(t_var *st)
{
	/* ft_putchar(*st->ptr);
	++st->char_count; */
	st->char_count += write(1, st->ptr, 1);
	return ;
}
